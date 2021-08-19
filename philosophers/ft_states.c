/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_states.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 12:03:02 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/18 14:42:16 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_eating(pthred_mutex_t mutex)
{
	pthread_mutex_lock(&mutex);

	pthread_mutex_unlock(&mutex);
}

void	ft_sleeping()
{

}

void	ft_thinking()
{
	
}