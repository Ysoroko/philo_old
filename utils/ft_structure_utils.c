/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structure_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:32:17 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/19 11:06:06 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/// Prints the values of the t_main_args structure
void	ft_print_main_args(t_main_args *main_args)
{
	printf("N Philos: [%d]\n", main_args->n_philos);
	printf("Time to die: [%d]\n", main_args->t_to_die);
	printf("Time to eat: [%d]\n", main_args->t_to_eat);
	printf("Time to sleep: [%d]\n", main_args->t_to_sleep);
	printf("Number to eat: [%d]\n", main_args->n_to_eat);
	printf("Current philo: [%d]\n", *(main_args->current_philo));
}
