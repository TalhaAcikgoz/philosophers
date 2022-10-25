#include "philo.h"

int ft_atoi(char *str)
{
	int i = 0;
	int n = 1;
	int res = 0;

	while(str[i] <= 32)
		i++;
	if(str[i] == '-' && str[i] == '+')
	{
		if(str[i] == '-')
			n = -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9' && str[i])
	{
		res *= 10;
		res += str[i] - 48;
		i++; 
	}
	return(res * n);
}

void    free_func(t_sim *sim)
{
	free(sim->philo);
	free(sim);
	(void)sim;
	return ;
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void    print(t_sim *sim, char *state, char c, int p_num)
{
	long current_time;
	current_time = get_time() - sim->start_time;
	pthread_mutex_lock(&sim->print_lock);
	if(!sim->is_died)
	{
		if (c == 'e')
			printf("\033[0;36m%3ld %3d %s\n\033[0m", current_time, p_num, state);
		else if (c == 'd')
			printf("\033[0;31m%3ld %3d %s\n\033[0m", current_time, p_num, state);
		else if (c == 'x')
			printf("\033[0;32m%3ld %3d %s\n\033[0m", current_time, p_num, state);
		else
			printf("\033[0;35m%3ld %3d %s\n\033[0m", current_time, p_num, state);
	}
	pthread_mutex_unlock(&sim->print_lock);
}

void	ft_wait(long long time, t_sim *sim)
{
	long long	t;

	t = get_time();
	while (!(sim->is_died))
	{
		usleep(32);
		if (get_time() - t >= time)
			break ;
	}
}