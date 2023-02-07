/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcrius <kcrius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:30:59 by kcrius            #+#    #+#             */
/*   Updated: 2022/07/05 20:31:00 by kcrius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

unsigned long	get_time_to_mls(void)
{
	struct timeval	tp;
	unsigned long	res;

	gettimeofday(&tp, NULL);
	res = (unsigned long)(tp.tv_sec * 1000 + tp.tv_usec / 1000);
	return (res);
}

void	kill_or_wait(int status, t_data *data)
{
	int	i;

	i = -1;
	while (status == 0 && ++i < data->input_data[PHIL_NB])
	{
		waitpid(-1, &status, 0);
		status >>= 8;
	}
	if (status == 255)
	{
		i = -1;
		while (++i < data->input_data[PHIL_NB])
			kill(data->phil_process->pid, SIGKILL);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc != 5 && argc != 6)
		exit(error("wrong number of arguments\n"));
	if (initializer(&data, argv, argc) < 0)
		exit(-1);
	i = -1;
	data.start = get_time_to_mls();
	while (++i < data.input_data[PHIL_NB])
	{
		data.phil_process[i].pid = fork();
		if (data.phil_process[i].pid < 0)
		{
			error("fork error\n");
			kill_or_wait(-1, &data);
			exit(-1);
		}
		if (data.phil_process[i].pid == 0)
			act(data.phil_process + i);
	}
	kill_or_wait(0, &data);
	exit (1);
}
