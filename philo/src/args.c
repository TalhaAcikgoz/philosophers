/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:33:46 by tacikgoz          #+#    #+#             */
/*   Updated: 2022/11/28 16:36:50 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_up_args(int argc, char **argv, t_data *data)
{
	data->should_eat = -1;
	data->n_philos = ft_atoi(argv[1]);
	data->tt_die = ft_atoi(argv[2]);
	data->tt_eat = ft_atoi(argv[3]);
	data->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->should_eat = ft_atoi(argv[5]);
	if (data->tt_die < 60 || data->tt_eat < 60 || data->tt_sleep < 60)
		philo_error("\"TTDIE or TTEAT or TTSLEEP < 60\"ARGS_TOO_SMALL",
			ARGS_ERROR);
	else if (data->n_philos > 200)
		philo_error("\"NUM OF PHILO ARE BIGGER THAN>200\"ARG_TOO_BIG",
			ARGS_ERROR);
	data->action = 0;
	data->running = true;
}

int	check_args(int argc, char **argv)
{
	int	x;
	int	y;

	if (!(argc == 6 || argc == 5))
		return (-1);
	y = 1;
	while (y < argc)
	{
		x = 0;
		while (argv[y][x])
		{
			if (!(argv[y][x] >= '0' && argv[y][x] <= '9'))
				return (-1);
			x++;
		}
		y++;
	}
	return (1);
}
