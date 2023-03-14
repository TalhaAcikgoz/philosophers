/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:43:43 by rtosun            #+#    #+#             */
/*   Updated: 2022/11/28 16:41:55 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers_bonus.h"

void	ft_seminit(t_simulation *sim)
{
	sem_unlink("./p_typing");
	sem_unlink("./p_forks");
	sim->typing = sem_open("./p_typing", O_CREAT, S_IRWXG, 1);
	sim->forks = sem_open("./p_forks", O_CREAT, S_IRWXG, sim->phil_count);
	if (sim->forks <= 0 || sim->typing <= 0)
		print_error_b("sem_open hatasi");
}

void	phil_init(t_simulation *sim)
{
	int	i;

	i = sim->phil_count;
	while (--i >= 0)
	{
		sim->philosophers[i].id = i + 1;
		sim->philosophers[i].last_eat = get_time_b();
		sim->philosophers[i].i_eat = 0;
		sim->philosophers[i].sim = sim;
	}
}

void	init_all_b(t_simulation *sim, char **argv)
{
	sim->phil_count = ft_atoi_b(argv[1]);
	sim->die_time = ft_atoi_b(argv[2]);
	sim->eat_time = ft_atoi_b(argv[3]);
	sim->sleep_time = ft_atoi_b(argv[4]);
	sim->is_dead = false;
	sim->all_eatedboii = false;
	sim->start_time = get_time_b();
	sim->philosophers = malloc(sizeof(t_philosopher) * sim->phil_count);
	if (argv[5])
		sim->eat_counter = ft_atoi_b(argv[5]);
	else
		sim->eat_counter = -1;
	ft_seminit(sim);
	phil_init(sim);
}
