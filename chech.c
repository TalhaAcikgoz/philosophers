#include "philo.h"

int	check_meal(t_philo *philo)
{
	int p_id_;

	p_id_ = 0;
	if (philo->sim->total_meal > 0)
	{
		printf("total meal : %d\n", philo->sim->total_meal);
		while (p_id_ < philo->sim->philo_num)
		{
			printf("philo[%d] eat count: %d\n", p_id_, philo->eat_count);
			if (philo[p_id_].eat_count == philo->sim->must_eat)
				philo->sim->total_meal++;
			p_id_++;
		}
		if (philo->sim->total_meal >= philo->sim->philo_num)
		{
			philo->sim->is_died = 1;
			return (1);
		}
	}
	return (0);
}