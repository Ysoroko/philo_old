/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structure_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:32:17 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/20 10:27:54 by ysoroko          ###   ########.fr       */
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
}

/// Creates a new t_philo structure and assigns its values
t_philo	*ft_initialize_philo(t_main_args *main_args, int number)
{
	t_philo	*ret;

	ret = malloc(sizeof(t_philo));
	if (!ret)
		return (NULL);
	ret->philo_number = number;
	ret->t_to_die = main_args->t_to_die;
	ret->t_to_sleep = main_args->t_to_sleep;
	ret->t_to_eat = main_args->n_to_eat;
	ret->n_to_eat = 0;
	if (main_args->n_to_eat)
		ret->n_to_eat = main_args->n_to_eat;
	ret->n_times_ate = 0;
	ret->start_time = 0;
	ret->current_time = 0;
	ret->n_seconds_without_eating = 0;
	ret->state = 0;
	return (ret);
}
