/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:33:48 by tacikgoz          #+#    #+#             */
/*   Updated: 2022/11/28 16:33:49 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	args_error_info(char *error)
{
	printf("\nERROR: %s\n\n", error);
	printf("USAGE_EXAMPLE: ./philo $(NOP) $(TTD) $(TTE) $(TTS) $(NOTEPME)\n");
	printf("NOT: Values can't be negative and they should be in milliseconds\n");
	printf("$(NOP): Number of philosophers\n");
	printf("$(TTD): Time to die\n");
	printf("$(TTE): Time to eat\n");
	printf("$(TTS): Time to sleep\n");
	printf("$(NOTEPME): (OPTIONAL) Number of times each philosopher must eat\n");
}

void	malloc_error_info(char *error)
{
	printf("\nERROR: %s\n\n", error);
	printf("ALLOCATING MEMORY FAILED\n");
	printf("TRY EXECUTING ONCE MORE\n");
}

void	philo_error(char *error, int error_id)
{
	if (error_id == ARGS_ERROR)
		args_error_info(error);
	else if (error_id == MALLOC_ERROR)
		malloc_error_info(error);
	exit(ERROR);
}
