#include "philo.h"

void	sim_init(t_sim *sim, int ac, char **av)
{
	sim->philo_num 	= ft_atoi(av[1]);
	if (sim->philo_num == 1)
	{
		printf("Philo 1 died...\n");
		free(sim);
		return ;
	}
	sim->time_die 	= ft_atoi(av[2]);
	sim->time_eat 	= ft_atoi(av[3]);
	sim->time_sleep = ft_atoi(av[4]);
	sim->must_eat = 0;
	if (ac == 6)
		sim->must_eat = ft_atoi(av[5]);
	sim->total_meal = 0;
	sim->is_died = 0;
	sim->fork_lock = malloc(sizeof(pthread_mutex_t) * sim->philo_num);
	pthread_mutex_init(&sim->print_lock, NULL);
}

void philo_init(t_sim *sim, t_philo *philo)
{
	int	i;

	i=0;
	
	while (i < sim->philo_num)
	{
		philo[i].p_id = i;
		philo[i].l_fork = i;
		philo[i].r_fork = i + 1 % sim->philo_num;
		philo[i].eat_count = 0;
		philo[i].last_eatTime = get_time();
		philo[i].sim = sim;
		pthread_mutex_init(&sim->fork_lock[i], NULL);
		i++;
	}
}

void	finish_dinner(t_philo *philo, t_sim *data)
{
	int	fork_id;

	fork_id = 0;
	while (fork_id < data->philo_num)
	{
		pthread_mutex_destroy(&data->fork_lock[fork_id]);
		fork_id++;
	}
	pthread_mutex_destroy(&data->print_lock);
	free(data->fork_lock);
	free(philo);
	return ;
}

int main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		t_philo *philo;
		t_sim *sim;

		sim =(t_sim *)malloc(sizeof(t_sim));
		if (!sim)
		{
			free(sim);
			return(0);
		}
		sim_init(sim, ac, av);
		if (!(philo = (t_philo *)malloc(sizeof(t_philo) * sim->philo_num )))
			free_func(sim);
		philo_init(sim, philo);
		start_dinner(philo);
		finish_dinner(philo, sim);
	}
	else
	{
		printf("Arguman Sayisi fazla veya az\n");
		return (-1);
	}
	return (0);
}
