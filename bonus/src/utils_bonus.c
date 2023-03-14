/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:43:58 by rtosun            #+#    #+#             */
/*   Updated: 2022/05/29 03:03:03 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers_bonus.h"

void	print_error_b(char *message)
{
	printf("%s%s\n", CRED, message);
	exit(0);
}

void	act_printer_b(t_philosopher *phil, t_simulation *sim, char *msg)
{
	sem_wait(sim->typing);
	if (!sim->is_dead)
	{
		printf("ms : %lli ", get_time_b() - sim->start_time);
		printf("phil : %i %s\n", phil->id, msg);
	}
	sem_post(sim->typing);
}

long long	get_time_b(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	i_need_sleep_b(t_simulation *sim, long long time)
{
	long long	this_time;

	this_time = get_time_b();
	while (!sim->is_dead)
	{
		if (get_time_b() - this_time >= time)
			break ;
		usleep (42);
	}
}

int	ft_atoi_b(char *ptr)
{
	int	res;
	int	pn;
	int	i;

	i = 0;
	pn = 1;
	res = 0;
	while (ptr[i] == ' ' || (ptr[i] >= 9 && ptr[i] <= 13))
		i++;
	while (ptr[i] == '+' || ptr[i] == '-')
	{
		if (ptr[i] == '-')
			pn *= -1;
		i++;
	}
	while ((ptr[i] >= '0' && ptr[i] <= '9') && ptr[i])
	{
		res = (res * 10) + ptr[i] - 48;
		i++;
	}
	return (res * pn);
}
