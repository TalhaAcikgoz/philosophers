#include "philo.h"

void	eat(t_sim *sim, int p_id)
{
	pthread_mutex_lock(&sim->fork_lock[sim->philo->l_fork]);
	pthread_mutex_lock(&sim->fork_lock[sim->philo->r_fork]);
	print(sim, "has taken left fork", 'e', p_id);
	print(sim, "has taken right fork", 'e', p_id);
	print(sim, "is eating", 'x', p_id);
	ft_wait(sim->time_eat, sim);
	sim->philo->last_eatTime = get_time();
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

	
	philo = (t_philo *)ptr;
	sim = (t_sim *)philo->sim;
	while (!check_meal(sim))
	{
		_phi_id = 0;
		while (_phi_id < sim->philo_num)
		{
			if (get_time() - philo[_phi_id].last_eatTime > sim->time_die)
			{
				//printf("%ld  %ld\n", get_time(), sim->philo[_phi_id].last_eatTime);
				print(sim, "philo is died", 'd', _phi_id);
				sim->is_died = 1;
				return (NULL);
			}
			_phi_id++;
		}
		ft_wait(10, sim);
	}
	return (NULL);
}

void	*loop(void *ptr)
{
	t_philo	*philo;
	t_sim   *sim;
	
	philo = ptr;
	sim = (t_sim *)philo->sim;
	if (sim->philo->p_id % 2 != 0)
		usleep(1600);
	while (sim->is_died != 1)
	{
		eat(sim, philo->p_id);
		print(sim, "is sleeping", 'f', philo->p_id);
		ft_wait(sim->time_sleep, sim);
		print(sim, "is thinking", 'f', philo->p_id);
		usleep(1000);
		philo->eat_count++;
	}
	return (NULL);
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
		if (pthread_create(&philo[p_id_].thread, NULL, &loop, &philo[p_id_]))
			return (-1);
	}
	if(pthread_create(&monitor, NULL, &observer, philo) == -1)
		return (-1);
	p_id_ = -1;
	while (++p_id_ < sim->philo_num)
	{
		pthread_join(sim->philo[p_id_].thread, NULL);
	}
	pthread_join(monitor, NULL);
	return (1);
}
