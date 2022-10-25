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
    int p_id_;

    p_id_ = 0;
    if (sim->total_meal > 0)
    {
        while (p_id_ < sim->philo_num)
        {
            if (sim->philo[p_id_].eat_count == sim->must_eat)
                sim->total_meal++;
            p_id_++;
        }
        if (sim->total_meal >= sim->philo_num)
        {
            sim->is_died = 1;
            return (1);
        }
    }
    return (0);
}