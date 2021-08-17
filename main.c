/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:04:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/17 16:09:16 by ysoroko          ###   ########.fr       */
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

/// Transforms the arguments of our program into integers and stores the values
/// inside the corresponding elements of our t_main_args structure.
/// Number of times to eat before stopping is left at 0 if not specified.
static void	ft_initialize_main_args(t_main_args *m_args, int argc, char **argv)
{
	m_args->n_philos = (int)(ft_atol(argv[1]));
	m_args->t_to_die = (int)(ft_atol(argv[2]));
	m_args->t_to_eat = (int)(ft_atol(argv[3]));
	m_args->t_to_sleep  = (int)(ft_atol(argv[4]));
	if (argc == 6)
		m_args->n_to_eat = (int)(ft_atol(argv[5]));
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
	//pthread_t	thread;
	t_main_args	*main_args;

	if (ft_main_args_error(argc, argv))
		return (-1);
	main_args = ft_new_main_args();
	if (!main_args)
		return (ft_puterr("Call to malloc function returned a NULL pointer"));
	ft_initialize_main_args(main_args, argc, argv);
	return (0);
}
