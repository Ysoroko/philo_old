/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structure_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:32:17 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/20 16:10:05 by ysoroko          ###   ########.fr       */
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

/// Prints the values of t_philo structure
void	ft_print_philo(t_philo	*philo)
{
	printf("\n\n\n");
	printf("____________________________________________________________________\n");
	printf("Philo number: [%d]\n", philo->philo_number);
	printf("Time to die: [%d]\n", philo->t_to_die);
	printf("Time to sleep: [%d]\n", philo->t_to_sleep);
	printf("Time to eat: [%d]\n", philo->t_to_eat);
	printf("N to eat: [%d]\n", philo->n_to_eat);
	printf("N_times_ate: [%d]\n", philo->n_times_ate);
	printf("Start time: [%d]\n", philo->start_time);
	printf("Current time: [%d]\n", philo->current_time);
	printf("N seconds without eating: [%d]\n", philo->n_seconds_without_eating);
	printf("State: [%d]\n", philo->state);
	printf("Left fork address: [%p]\n", philo->left_fork);
	printf("Right fork address: [%p]\n", philo->right_fork);
	printf("\n____________________________________________________________________");
	printf("\n\n\n");
}

/// Creates a new t_philo structure and assigns its values
t_philo	*ft_initialize_philo(t_main_args *args, int n, t_philo **f)
{
	t_philo	*ret;

	ret = malloc(sizeof(t_philo));
	if (!ret)
		return (NULL);
	ret->philo_number = n;
	ret->t_to_die = args->t_to_die;
	ret->t_to_sleep = args->t_to_sleep;
	ret->t_to_eat = args->n_to_eat;
	ret->n_to_eat = 0;
	if (args->n_to_eat)
		ret->n_to_eat = args->n_to_eat;
	ret->n_times_ate = 0;
	ret->start_time = 0;
	ret->current_time = 0;
	ret->n_seconds_without_eating = 0;
	ret->state = 0;
	if (!(n - 1))
		*f = ret;
	return (ret);
}

/// Frees to_free argument, displays error_msg argument and returns to_return
void	*ft_free(void *to_free, char *error_msg, void *to_return)
{
	free(to_free);
	if (error_msg)
		ft_puterr(error_msg);
	return (to_return);
}

/// Frees to_free argument, displays error_msg argument and returns to_return
int		ft_free_int_ret(void *to_free, char *error_msg, int to_return)
{
	free(to_free);
	if (error_msg)
		ft_puterr(error_msg);
	return (to_return);
}

/// Mallocs size bytes at *malloc_this memory adress
/// Returns the return value of malloc call
void	*ft_malloc(int size, void **malloc_this)
{
	if (!malloc_this)
		return (NULL);
	*malloc_this = malloc(size);
	return (malloc_this);
}