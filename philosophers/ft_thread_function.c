/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:32:41 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/19 11:56:51 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/// Function called when creating a new thread
void	*ft_thread_function(void *arg)
{
	t_philo	*philo;
	int		number;

	usleep(100);
	philo = (t_philo *)arg;
	number = philo->philo_number;
	printf("hey i'm a philo number %d\n", number);
	return (arg);
}
