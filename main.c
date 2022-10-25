#include "philo.h"

/* void	write_philo(t_sim *sim)
{
	int t;
	int	i;
	i=0;
	while (i < sim->philo_num)
	{
		t = sim->philo[i].l_fork;
		//printf("%d ", t);
		//fflush(stdout);
		i++;
	}
} */

t_sim	*sim_init(t_sim *sim, int ac, char **av)
{
	sim->philo_num 	= atoi(av[1]);
	sim->time_die 	= atoi(av[2]);
	sim->time_eat 	= atoi(av[3]);
	sim->time_sleep = atoi(av[4]);
	if (ac == 6)
		sim->must_eat = atoi(av[5]);
	sim->total_meal = 0;
	pthread_mutex_init(&sim->print_lock, NULL);
	return (sim);
}

void philo_init(t_sim *sim)
{
	int	i;

	i=0;
	if (!(sim->philo = (t_philo *)malloc(sizeof(t_philo) * sim->philo_num)))
		free_func(sim);
    sim->fork_lock = malloc(sizeof(pthread_mutex_t) * sim->philo_num);
	while (i < sim->philo_num)
	{
		sim->philo[i].p_id = i;
		sim->philo[i].l_fork = i;
		sim->philo[i].r_fork = i + 1 % sim->philo_num;
		sim->philo[i].sim = (struct t_sim *)sim;
		pthread_mutex_init(&sim->fork_lock[i], NULL);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		t_sim *sim;
		sim =(t_sim *)malloc(sizeof(t_sim));
		if (!sim)
			free_func(sim);
		sim = sim_init(sim, ac, av);
		philo_init(sim);
		start_dinner(sim);
	}
	else
	{
		printf("Arguman Sayisi fazla veya az\n");
		return (0);
	}
}