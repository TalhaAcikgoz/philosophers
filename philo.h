#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

struct t_sim;

typedef struct s_philo
{
	pthread_t		thread;
	int				l_fork;
	int				r_fork;
	int				p_id;
	int				total_meal;
	struct t_sim	*sim;
}	t_philo;

typedef struct s_sim
{
	pthread_mutex_t	print_lock;
	pthread_mutex_t	*fork_lock;
	t_philo			*philo;
	int				is_died;
	int				philo_num;
	long			start_time;
	int				time_sleep;
	int				time_die;
	int				time_eat;
	int				must_eat;
}	t_sim;

int		ft_atoi(char *str);
void	free_func(t_sim *sim);
t_sim	*sim_init(t_sim *sim, int ac, char **av);
void	philosophers(int ac, char **av);
void	philo_init(t_sim *sim);
long	get_time(void);
int		start_dinner(t_sim *sim);
void	print(t_sim *sim, char *state, char c, int p_num);
void	*loop(void *ptr);
int		start_dinner(t_sim *sim);
void	eat(t_sim *sim, int p_id);
void	ft_wait(long long time, t_sim *sim);

#endif