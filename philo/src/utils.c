/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:34:02 by tacikgoz          #+#    #+#             */
/*   Updated: 2022/11/28 16:34:03 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long int	get_ms(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (unsigned long int)1000) + (tv.tv_usec / 1000));
}

void	print_action(char *action, t_philo *philo, unsigned long int ms)
{
	if (philo->data->running == false)
		return ;
	pthread_mutex_lock(&philo->data->write);
	printf("%lu:ms %d %s\n", ms - philo->data->start, philo->id + 1, action);
	pthread_mutex_unlock(&philo->data->write);
}

int	ft_atoi(char *nbr)
{
	int	index;
	int	sign;
	int	number;

	sign = 1;
	index = 0;
	number = 0;
	while ((nbr[index] <= 13 && nbr[index] >= 9) || nbr[index] == ' ')
		index++;
	if (nbr[index] == '-')
		sign *= -1;
	else if (nbr[index] == '+')
		index++;
	while (nbr[index] >= '0' && nbr[index] <= '9')
	{
		number *= 10;
		number += (nbr[index] - '0');
		index++;
	}
	return (number * sign);
}
