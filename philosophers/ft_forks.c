/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:36:39 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/20 15:36:56 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/// This function creates a mutex for every fork and assigns 2 forks to
/// every philosopher, both shared with neighbours.
/// Returns 0 in case of success or -1 in case of an error
int	ft_initialize_forks(t_philo *ph, int n, t_philo *prev, t_philo *f)
{
	pthread_mutex_t	*left_fork;

	left_fork = malloc(sizeof(*left_fork));
	if (!left_fork)
		return (ft_puterr("Failed to malloc a mutex fork"));
	if (pthread_mutex_init(left_fork, NULL))
		return (ft_puterr("Failed to initialize a mutex for the fork"));
	if (!prev)
		ph->left_fork = left_fork;
	else if (ph->philo_number == n)
	{
		ph->left_fork = left_fork;
		ph->right_fork = f->left_fork;
		prev->right_fork = left_fork;
	}
	else
	{
		ph->left_fork = left_fork;
		prev->right_fork = left_fork;
	}
	return (0);
}
