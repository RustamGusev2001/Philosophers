/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcrius <kcrius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:30:16 by kcrius            #+#    #+#             */
/*   Updated: 2022/07/05 20:30:18 by kcrius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc != 5 && argc != 6)
		return (error("wrong number of arguments\n"));
	if (initializer(&data, argv, argc) < 0)
		return (-1);
	i = -1;
	data.start = get_time_to_mls();
	while (++i < data.input_data[PHIL_NB])
	{
		if (pthread_create(&(data.phil_treads[i].thread), \
		NULL, act, &data.phil_treads[i]) != 0)
		{
			all_clean(&data);
			return (error("thread error\n"));
		}
		pthread_mutex_lock(&(data.last_time_eating));
		data.phil_treads[i].last_time_eat = get_time_to_mls();
		pthread_mutex_unlock(&(data.last_time_eating));
	}
	check_dead_and_eat_all(&data);
	return (1);
}
