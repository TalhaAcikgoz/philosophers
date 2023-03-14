/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:33:51 by tacikgoz          #+#    #+#             */
/*   Updated: 2022/11/28 16:33:52 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_philo(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->write);
	while (++i < data->n_philos)
		pthread_mutex_destroy(&data->fork[i]);
	free(data->fork);
	free(data->philo);
}
