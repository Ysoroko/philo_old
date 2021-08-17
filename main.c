/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:04:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/17 15:44:05 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


/// Check the arguments of our program for errors.
/// Returns 1 and displays the corresponding error message if an error is found
/// Returns 0 otherwise.
static int	ft_main_args_error(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc > 6 || argc < 5)
		return (ft_puterr("Wrong number of arguments"));
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_strchr(BASE_TEN, argv[i][j]))
				return (ft_puterr("Found non numerical input"));
		}
		if (ft_atol(argv[i]) <= 0 || ft_atol(argv[i]) > INT_MAX)
			return (ft_puterr("Outside integers in range [1 ; 2147483647]"));
	}
	return (0);
}

/*
** 1 - number of philosophers
** 2 - time to die
** 3 - time to eat
** 4 - time to sleep
** (optionnal) 5 - number of times they need to eat
*/

int	main(int argc, char **argv)
{
	pthread_t	thread;
	int			n_philosophers;
	int			t_to_die;
	int			t_to_eat;
	int			t_to_sleep;
	int			i;

	if (ft_main_args_error(argc, argv))
		return (-1);
	ft_putstr_fd("All good, moving on\n", STDOUT);
	ft_new_main_args()
	return (0);
}
