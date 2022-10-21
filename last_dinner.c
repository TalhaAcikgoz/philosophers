#include "philo.h"

void	eat(t_sim *sim)
{
    pthread_mutex_lock(&sim->fork_lock[sim->philo->l_fork]);
	pthread_mutex_lock(&sim->fork_lock[sim->philo->r_fork]);
	print(sim, "has taken left fork", 'f', sim->philo->p_id);
	print(sim, "has taken right fork", 'f', sim->philo->p_id);
	print(sim, "is eating", 'e', sim->philo->p_id);
	ft_wait(sim->time_eat, sim);
	pthread_mutex_unlock(&sim->fork_lock[sim->philo->l_fork]);
	pthread_mutex_unlock(&sim->fork_lock[sim->philo->r_fork]);
	return ;
}

void	*loop(void *ptr)
{
	//eat, think, sleep
	t_philo	*philo;
    t_sim   *sim;
	
	philo = ptr;
    sim = (t_sim *)philo->sim;
	eat(sim);
	return (0);
}

int	start_dinner(t_sim *sim)
{
	int     p_id_;
    t_philo *philo;
	//pthread_t monitor;

    philo = sim->philo;
	p_id_ = -1;
	sim->start_time = get_time();
	while (++p_id_ < sim->philo_num)
	{
		if (pthread_create(&sim->philo[p_id_].thread, NULL, &loop, &philo[p_id_]))
			return (-1);
		else
			usleep(1000);
	}
    p_id_ = -1;
    while (++p_id_ < sim->philo_num)
    {
        pthread_join(sim->philo[p_id_].thread, NULL);
    }
	return (0);
}
