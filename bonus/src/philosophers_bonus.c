/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:43:49 by rtosun            #+#    #+#             */
/*   Updated: 2022/05/12 16:30:17 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_simulation	sim;

	if (argc != 5 && argc != 6)
		print_error_b("Eksik veya fazla arguman");
	init_all_b(&sim, argv);
	ft_simulation_b(&sim);
}
