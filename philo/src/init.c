/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:33:54 by tacikgoz          #+#    #+#             */
/*   Updated: 2022/11/28 16:42:59 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_up_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = (t_philo *) malloc(sizeof(t_philo) * data->n_philos);
	if (!data->philo)
		philo_error("\"DATA->PHILO ALLOCATION FAILED\" malloc() RETURNED NULL",
			MALLOC_ERROR);
	while (i < data->n_philos)
	{
		data->philo[i].id = i;
		data->philo[i].r_fork = i;
		data->philo[i].l_fork = (i + 1) % data->n_philos;
		data->philo[i].eat_count = 0;
		data->philo[i].data = (t_data *) data;
		data->philo[i].last_eat = 0;
		data->philo[i].finished = false;
		i++;
	}
}

static void	set_up_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->n_philos);
	if (!data->fork)
		philo_error("\"DATA->FORK ALLOCATION FAILED\" malloc() RETURNED NULL",
			MALLOC_ERROR);
	while (i < data->n_philos)
		pthread_mutex_init(&data->fork[i++], NULL);
	pthread_mutex_init(&data->write, NULL);
}

static void	set_up_threads(t_data *data)
{
	int			i;
	int			p_id_;
	pthread_t	id;

	i = -1;
	while (++i < data->n_philos)
		pthread_create(&data->philo[i].thread_id, NULL,
			&philo_main_loop, &data->philo[i]);
	pthread_create(&id, NULL, &philo_maintain, data);
	p_id_ = -1;
	while (++p_id_ < data->philo->data->n_philos)
	{
		pthread_join(data->philo[p_id_].thread_id, NULL);
		pthread_detach(data->philo[p_id_].thread_id);
	}
	pthread_join(id, NULL);
	pthread_detach(id);
}

void	start_philo(int argc, char **argv, t_data *data)
{
	set_up_args(argc, argv, data);
	set_up_philo(data);
	set_up_mutex(data);
	set_up_threads(data);
}

// for (int i = 0; i < data->n_philos; i++)
//printf("id: %d\n r_fork: %d\n l_fork: %d\n eat_count:
//%d\n", data->philo[i].id,
//data->philo[i].r_fork, data->philo[i].l_fork, data->philo[i].eat_count);

//printf("n_philo: %d\ntt_die: %d\ntt_eat: %d\ntt_sleep: %d\nshould_eat %d\n",
//data->n_philos, data->tt_die, data->tt_eat, data->tt_sleep, data->should_eat);