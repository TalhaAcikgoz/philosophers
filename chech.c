#include "philo.h"

int check_args(t_sim *sim)
{
    if (sim->must_eat < 1 || sim->time_die < 1 || sim->time_eat < 1 || sim->time_sleep < 1)
    {
        printf("girilen arglar 1 den kucuk olamaz\n");
        return (-1);
    }
    return (1);
}

int check_meal(t_sim *sim)
{
    if (sim->philo->total_meal == sim->philo_num)
    {
        
    }
    return (0);
}