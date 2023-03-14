/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:33:42 by tacikgoz          #+#    #+#             */
/*   Updated: 2022/11/28 16:33:43 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pthink(t_philo *philo)
{
	print_action(STR_THINKING, philo, get_ms());
}

void	peat(t_philo *philo)
{
	unsigned long int	time;

	time = get_ms();
	print_action(STR_EATING, philo, time);
	philo->last_eat = time;
	philo->eat_count++;
	usleep(philo->data->tt_eat * 1000);
}

void	psleep(t_philo *philo)
{
	print_action(STR_SLEEPING, philo, get_ms());
	usleep(philo->data->tt_sleep * 1000);
}

void	ptake_forks(t_philo *philo)
{
	unsigned long int	time;

	time = get_ms();
	pthread_mutex_lock(&philo->data->fork[philo->r_fork]);
	print_action(STR_TOOK_FORK, philo, time);
	pthread_mutex_lock(&philo->data->fork[philo->l_fork]);
	print_action(STR_TOOK_FORK, philo, time);
}

void	pdrop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->fork[philo->r_fork]);
	pthread_mutex_unlock(&philo->data->fork[philo->l_fork]);
}
