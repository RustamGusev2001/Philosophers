/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcrius <kcrius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:30:05 by kcrius            #+#    #+#             */
/*   Updated: 2022/07/05 20:30:07 by kcrius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_malloc(t_data *data)
{
	free(data->phil_treads);
	free(data->forks);
}

void	all_clean(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->input_data[PHIL_NB])
		pthread_mutex_destroy(data->forks + i);
	pthread_mutex_destroy(&data->std_out);
	pthread_mutex_destroy(&data->last_time_eating);
	pthread_mutex_destroy(&data->dead_check);
	pthread_mutex_destroy(&data->check_eat_times);
	free_malloc(data);
}
