/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:04:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/09/02 11:37:26 by ysoroko          ###   ########.fr       */
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
		if (ft_strlen(argv[i]) > ft_strlen("2147483647")
			|| ft_atol(argv[i]) <= 0 || ft_atol(argv[i]) > INT_MAX)
			return (ft_puterr("Outside integers in range [1 ; 2147483647]"));
	}
	return (0);
}

/// Initializes the "display" mutex
/// Returns the mutex or a NULL pointer in case of an error
static pthread_mutex_t	*ft_initialize_display_mutex(void)
{
	pthread_mutex_t	*displaying;

	if (!ft_malloc(sizeof(pthread_mutex_t), (void **)&displaying))
		return (NULL);
	if (pthread_mutex_init(displaying, NULL))
		return (ft_free(displaying, "Failed to init a display mutex", NULL));
	return (displaying);
}

/// Initializes the t_philo structure, and the mutexes
/// Returns 0 in case of success or -1 if an error
static int	ft_init(t_philo **ph, t_main_args *args, int i, pthread_mutex_t *d)
{
	ph[2] = ft_initialize_philo(args, i + 1, &(ph[0]));
	if (!ph[2])
		return (ft_puterr("Failed to initialize a t_philo"));
	if (ft_initialize_forks_mutex(ph[2], args->n_philos, ph[1], ph[0]))
		return (-1);
	ph[2]->displaying = d;
	return (0);
}

/// Initialize an array of threads of n_philos elements with malloc
/// Creates a thread for every philosopher and joins the threads
/// Returns a NULL pointer in case of an error
static pthread_t	*ft_initialize_threads(t_main_args *args)
{
	pthread_t		*ret;
	t_philo			*ph[3];
	pthread_mutex_t	*displaying;
	int				i;

	if (!ft_malloc(sizeof(*ret) * args->n_philos, (void **)&ret))
		return (ft_puterr_ptr("Failed to malloc the philosophers"));
	i = -1;
	displaying = ft_initialize_display_mutex();
	ph[0] = NULL;
	if (!displaying)
		return (NULL);
	while (++i < args->n_philos)
	{
		if (ft_init(ph, args, i, displaying))
			return (ft_free(ret, NULL, NULL));
		if (pthread_create(&(ret[i]), NULL, &ft_thread_function, ph[2]))
			return (ft_free(ret, "Failed to create a thread", NULL));
		ph[0] = ph[2];
	}
	while (--i >= 0)
		if (pthread_join(ret[i], NULL))
			return (ft_free(ret, "Failed to join a thread", NULL));
	return (ret);
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
	t_main_args	*main_args;
	pthread_t	*threads;
	t_philo		**philos;

	if (ft_main_args_error(argc, argv))
		return (-1);
	// PHILOS TO BE MALLOC'D HERE
	philos = malloc(sizeof(t_philo *) * ft_atol(argv[1]));
	if (!philos)
		return (ft_puterr("Failed to malloc the philosophers array"));
	main_args = ft_initialize_main_args_struct(argc, argv);
	if (!main_args)
		return (ft_free_int_ret(philos, NULL, -1));
	//if (!philos)
	//	return (ft_puterr("Couldn't malloc philos array"));
	threads = ft_initialize_threads(main_args);
	if (!threads)
		return (-1);
	free(main_args);
	free(threads);
	return (0);
}
