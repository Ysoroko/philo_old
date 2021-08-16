/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:04:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/16 14:01:04 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** static int	ft_main_args_error(int argc, char **argv)
** This function is used to check the arguments of our program for errors.
** Returns 1 and displays the corresponding error message if an error is found.
** Returns 0 otherwise.
*/

static int	ft_main_args_error(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc > 6 || argc < 5)
		return (ft_puterr("Wrong number of arguments"));
	i = 0;
	j = -1;
	while (++i < argc)
	{
		if (!ft_strchrset(argv[i], BASE_TEN))
			return (ft_puterr("Found non numerical input"));
		if (ft_atol(argv[i]) <= 0 || ft_atol(argv[i]) > INT_MAX)
			return (ft_puterr("Only integer values are accepted"));
	}
	return (0);
}

/*
** Each program should have the same options: number_of_philosophers time_to_die
** time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat
** 1 - number of philosophers
** 2 - time to die
** 3 - time to eat
** 4 - time to sleep
** (optionnal) 5 - number of times they need to eat
*/

int	main(int argc, char **argv)
{
	if (ft_main_args_error(argc, argv))
		return (-1);
	ft_putstr_fd("All good, moving on\n", STDOUT);
	return (0);
}
