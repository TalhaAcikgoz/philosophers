#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_sim
{
	pthread_mutex_t	print_lock;
	pthread_mutex_t	*fork_lock;
	int				total_meal;
	int				is_died;
	int				philo_num;
	long			start_time;
	int				time_sleep;
	int				time_die;
	int				time_eat;
	int				must_eat;
}	t_sim;

typedef struct s_philo
{
	pthread_t		thread;
	int				p_id;
	int				l_fork;
	int				r_fork;
	int				eat_count;
	long			last_eatTime;
	t_sim			*sim;
}	t_philo;

//main
void	sim_init(t_sim *sim, int ac, char **av);
void 	philo_init(t_sim *sim, t_philo *philo);
void	finish_dinner(t_philo *philo, t_sim *data);
//last_dinner
void	eat(t_philo *philo, int p_id);
void	observer(void *ptr);
void	*loop(void *ptr);
int		start_dinner(t_philo *philo);

//utils
int		ft_atoi(char *str);
void    free_func(t_sim *sim);
long	get_time(void);
void	print(t_sim *sim, char *state, char c, int p_num);
void	ft_wait(long long time, t_sim *sim);

//check
int		check_meal(t_philo *philo);

#endif