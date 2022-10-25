#include "philo.h"

void	eat(t_sim *sim, int p_id)
{
	pthread_mutex_lock(&sim->fork_lock[sim->philo->l_fork]);
	pthread_mutex_lock(&sim->fork_lock[sim->philo->r_fork]);
	print(sim, "has taken left fork", 'e', p_id);
	print(sim, "has taken right fork", 'e', p_id);
	print(sim, "is eating", 'x', p_id);
	ft_wait(sim->time_eat, sim);
	pthread_mutex_unlock(&sim->fork_lock[sim->philo->l_fork]);
	pthread_mutex_unlock(&sim->fork_lock[sim->philo->r_fork]);
	print(sim, "has release left fork", 'd', p_id);
	print(sim, "has release right fork", 'd', p_id);
	return ;
}

void	*observer(void *ptr)
{
	t_philo *philo;
	t_sim	*sim;
	int		_phi_id;

	sim = philo->sim;
	philo = (t_philo *)ptr;
	while (!check_meals(philo))
	{
		_phi_id = 0;
		while (_phi_id < sim->philo_num)
		{
			if (get_time() - philo[_phi_id])
		}
	}
}

void	*loop(void *ptr)
{
	t_philo	*philo;
	t_sim   *sim;
	
	philo = ptr;
	sim = (t_sim *)philo->sim;
	eat(sim, philo->p_id);
	print(sim, "is sleeping", 'f', philo->p_id);
	ft_wait(sim->time_sleep, sim);
	print(sim, "is thinking", 'f', philo->p_id);
	usleep(1000);
	philo->eat_count++;
	return (0);
}

int	start_dinner(t_sim *sim)
{
	int     p_id_;
	t_philo *philo;
	pthread_t monitor;

	philo = sim->philo;
	p_id_ = -1;
	sim->start_time = get_time();
	while (++p_id_ < sim->philo_num)
	{
		if (pthread_create(&sim->philo[p_id_].thread, NULL, &loop, &philo[p_id_]))
			return (-1);
	}
	if(!(pthread_create(&monitor, NULL, &observer, philo)))
		return (-1);
	p_id_ = -1;
	while (++p_id_ < sim->philo_num)
	{
		pthread_join(sim->philo[p_id_].thread, NULL);
	}
	return (0);
}
