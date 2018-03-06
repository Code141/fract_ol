/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:57:39 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/06 15:29:18 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenCL/cl.h>
#include <libft.h>
#include <mlxyz.h>
#include <opencl/opencl.h>

int			get_platforms(t_opencl *opencl)
{
	opencl->platforms_count = 0;
	clGetPlatformIDs(0, NULL, &opencl->platforms_count);
	if (opencl->platforms_count)
	{
		opencl->platforms = (cl_platform_id*)malloc(
				sizeof(cl_platform_id) * opencl->platforms_count);
		clGetPlatformIDs(opencl->platforms_count, opencl->platforms, NULL);
		return (1);
	}
	else
		ft_putstr("No platform available\n");
	return (0);
}

int			get_devices(t_opencl *opencl)
{
	opencl->devices_count = 0;
	clGetDeviceIDs(opencl->platform, CL_DEVICE_TYPE_ALL, 0, NULL,
			&opencl->devices_count);
	if (opencl->devices_count)
	{
		opencl->devices = (cl_device_id*)malloc(
				sizeof(cl_device_id) * opencl->devices_count);
		clGetDeviceIDs(opencl->platform, CL_DEVICE_TYPE_ALL,
				opencl->devices_count, opencl->devices, NULL);
		return (1);
	}
	else
		ft_putstr("No devices available\n");
	return (0);
}

int				load_kernel(t_opencl *opencl, char **files, int number)
{
	opencl->program = clCreateProgramWithSource(opencl->context, number,
			(const char **)files, NULL, &opencl->ret);
	opencl->ret = clBuildProgram(opencl->program, 1, &opencl->device,
			"-I./includes -cl-fast-relaxed-math ", NULL, NULL);

		if (opencl->ret != CL_SUCCESS) {
			char *buff_erro;
			cl_int errcode;
			size_t build_log_len;
			errcode = clGetProgramBuildInfo(opencl->program, opencl->device, CL_PROGRAM_BUILD_LOG, 0, NULL, &build_log_len);
			if (errcode) {
				printf("clGetProgramBuildInfo failed at line %d\n", __LINE__);
				exit(-1);
			}

			buff_erro = malloc(build_log_len);
			if (!buff_erro) {
				printf("malloc failed at line %d\n", __LINE__);
				exit(-2);
			}

			errcode = clGetProgramBuildInfo(opencl->program, opencl->device, CL_PROGRAM_BUILD_LOG, build_log_len, buff_erro, NULL);
			if (errcode) {
				printf("clGetProgramBuildInfo failed at line %d\n", __LINE__);
				exit(-3);
			}

			fprintf(stderr,"Build log: \n%s\n", buff_erro); //Be careful with  the fprint
			free(buff_erro);
			fprintf(stderr,"clBuildProgram failed\n");
			exit(EXIT_FAILURE);
		}

	opencl->kernel = clCreateKernel(opencl->program, "luncher", &opencl->ret);
	if (opencl->ret)
		return (0);
	return (1);
}


t_opencl	*init_opencl(void)
{
	t_opencl	*opencl;

	opencl = (t_opencl*)malloc(sizeof(t_opencl));
	if (!opencl)
		return (NULL);
	ft_bzero(opencl, sizeof(t_opencl));
	ft_putstr("- Init OpenCl -\n");
	if (!get_platforms(opencl))
		return (NULL);
	if (!get_devices(opencl))
		return (NULL);
	opencl->platform = opencl->platforms[0];
	opencl->device = opencl->devices[1];
	opencl->context = clCreateContext(NULL, 1, &opencl->device, NULL, NULL,
			&opencl->ret);
	opencl->command_queue = clCreateCommandQueue(opencl->context,
			opencl->device, 0, &opencl->ret);
	free(opencl->platforms);
	free(opencl->devices);
	return (opencl);
}
