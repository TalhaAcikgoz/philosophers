#include "philo.h"

void	eat(t_philo *philo, int p_id)
{
	pthread_mutex_lock(&philo->sim->fork_lock[philo->l_fork]);
	pthread_mutex_lock(&philo->sim->fork_lock[philo->r_fork]);
	print(philo->sim, "has taken left fork", 'e', p_id);
	print(philo->sim, "has taken right fork", 'e', p_id);
	print(philo->sim, "is eating", 'x', p_id);
	ft_wait(philo->sim->time_eat, philo->sim);
	philo->last_eatTime = get_time();
	pthread_mutex_unlock(&philo->sim->fork_lock[philo->l_fork]);
	pthread_mutex_unlock(&philo->sim->fork_lock[philo->r_fork]);
	print(philo->sim, "has release left fork", 'd', p_id);
	print(philo->sim, "has release right fork", 'd', p_id);
	return ;
}

void	*observer(void *ptr)
{
	t_philo *philo;
	int		_phi_id;

	philo = (t_philo *)ptr;
	while (!check_meal(philo))
	{
		_phi_id = 0;
		while (_phi_id < philo->sim->philo_num)
		{
			if (( philo[_phi_id].last_eatTime - get_time() > philo->sim->time_die))
			{
				print(philo->sim, "---philo is died---", 'd', _phi_id);
				philo->sim->is_died = 1;
				return (NULL);
			}
			_phi_id++;
		}
		ft_wait(10, philo->sim);
	}
	return (NULL);
}

void	*loop(void *ptr)
{
	t_philo	*philo;

	philo = ptr;
	if (philo->p_id % 2 != 0)
		usleep(1600);
	while (philo->sim->is_died != 1)
	{
		eat(philo, philo->p_id);
		print(philo->sim, "is sleeping", 'f', philo->p_id);
		ft_wait(philo->sim->time_sleep, philo->sim);
		print(philo->sim, "is thinking", 'f', philo->p_id);
		philo->eat_count++;
	}
	return (NULL);
}

int	start_dinner(t_philo *philo)
{
	int     p_id_;
	pthread_t monitor;

	p_id_ = -1;
	philo->sim->start_time = get_time();
	while (++p_id_ < philo->sim->philo_num)
	{
		if (pthread_create(&philo[p_id_].thread, NULL, &loop, philo + p_id_))
			return (-1);
	}
	if (!pthread_create(&monitor, NULL, &observer, philo))
	p_id_ = -1;
	while (++p_id_ < philo->sim->philo_num)
	{
		pthread_join(philo[p_id_].thread, NULL);
	}
	pthread_join(monitor, NULL);
	return (1);
}
