/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_states.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 12:03:02 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/20 10:47:42 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_eating(t_philo *philo)
{
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	pthread_mutex_lock(&mutex);
	
	pthread_mutex_unlock(&mutex);
}

void	ft_sleeping()
{

}

void	ft_thinking()
{
	
}
