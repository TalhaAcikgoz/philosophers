/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:43:54 by rtosun            #+#    #+#             */
/*   Updated: 2022/11/28 17:47:26 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers_bonus.h"

void	eat_bro(t_simulation *sim, t_philosopher *phil)
{
	sem_wait(sim->forks);
	act_printer_b(phil, sim, "catali aldi..");
	sem_wait(sim->forks);
	act_printer_b(phil, sim, "catali aldi..");
	act_printer_b(phil, sim, "yiyor");
	phil->last_eat = get_time_b();
	i_need_sleep_b(sim, sim->eat_time);
	phil->i_eat++;
	sem_post(sim->forks);
	sem_post(sim->forks);
}

void	*thread(void *void_phil)
{
	t_philosopher	*phil;
	t_simulation	*sim;

	phil = (t_philosopher *)void_phil;
	sim = phil->sim;
	while (31 + 11)
	{
		if (get_time_b() - phil->last_eat > sim->die_time)
		{
			act_printer_b(phil, sim, "oldu");
			sim->is_dead = true;
			sem_wait(sim->typing);
			exit(1);
		}
		if (phil->i_eat >= sim->eat_counter && sim->eat_counter != -1)
			break ;
		usleep(1000);
	}
	return (NULL);
}

void	exit_sim(t_simulation *sim)
{
	int	ret;
	int	i;

	ret = 0;
	i = -1;
	while (++i < sim->phil_count)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = -1;
			while (++i < sim->phil_count)
				kill(sim->philosophers[i].p_id, SIGTERM);
		}
	}
	sem_close(sim->forks);
	sem_close(sim->typing);
	sem_unlink("./p_typing");
	sem_unlink("./p_forks");
}

void	*p_process(void *void_phil)
{
	t_philosopher	*phil;
	t_simulation	*sim;

	phil = (t_philosopher *)void_phil;
	sim = phil->sim;
	if (phil->id % 2 != 0)
		usleep(15000);
	pthread_create(&phil->dead_check, NULL, thread, void_phil);
	while (!sim->is_dead)
	{
		eat_bro(sim, phil);
		if (sim->eat_counter != -1 && phil->i_eat >= sim->eat_counter)
			break ;
		act_printer_b(phil, sim, "uyuyor");
		i_need_sleep_b(sim, sim->sleep_time);
		act_printer_b(phil, sim, "dusunuyor");
	}
	pthread_join(phil->dead_check, NULL);
	pthread_detach(phil->dead_check);
	exit(0);
}

int	ft_simulation_b(t_simulation *sim)
{
	int				i;
	t_philosopher	*phils;

	phils = sim->philosophers;
	i = -1;
	while (++i < sim->phil_count)
	{
		phils[i].p_id = fork();
		if (phils[i].p_id < 0)
			return (1);
		if (phils[i].p_id == 0)
			p_process(&phils[i]);
		usleep(100);
	}
	exit_sim(sim);
	return (0);
}
