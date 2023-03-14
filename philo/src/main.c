/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:33:56 by tacikgoz          #+#    #+#             */
/*   Updated: 2022/11/28 16:33:57 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv) == ERROR)
		philo_error("\"CHECK_ARGS(ARGC, ARGV)\" RETURNED_ERROR", ARGS_ERROR);
	start_philo(argc, argv, &data);
	end_philo(&data);
	return (0);
}
