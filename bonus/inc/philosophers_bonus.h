/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:34:13 by rtosun            #+#    #+#             */
/*   Updated: 2022/05/29 12:22:31 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

# define CNRM  "\x1B[0m"
# define CRED  "\x1B[31m"
# define CGRN  "\x1B[32m"
# define CYEL  "\x1B[33m"
# define CBLU  "\x1B[34m"
# define CMAG  "\x1B[35m"
# define CCYN  "\x1B[36m"
# define CWHT  "\x1B[37m"

struct	s_simulation;
typedef struct s_philosopher
{
	int					id;
	int					i_eat;
	long long			last_eat;
	pid_t				p_id;
	pthread_t			dead_check;
	struct s_simulation	*sim;
}		t_philosopher;

typedef struct s_simulation
{
	int				phil_count;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_counter;
	bool			is_dead;
	bool			all_eatedboii;
	long long		start_time;
	sem_t			*typing;
	sem_t			*forks;
	t_philosopher	*philosophers;
}		t_simulation;

void		init_all_b(t_simulation *sim, char **argv);
void		print_error_b(char *message);
int			ft_simulation_b(t_simulation *sim);
long long	get_time_b(void);
void		act_printer_b(t_philosopher *phil, t_simulation *sim, char *msg);
void		i_need_sleep_b(t_simulation *sim, long long time);
int			ft_atoi_b(char *ptr);

#endif