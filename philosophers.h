/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:20:51 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/24 12:04:42 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

/*
** STRUCTURES
*/

/// Structure used to store our main arguments values
/// Its elements are:
/// n_philos - number of philosophers
/// t_to_die - time to die
/// t_to_eat - time to eat
/// t_to_sleep - time to sleep
/// (optionnal) n_to_eat - number of times they need to eat before stopping
typedef struct s_main_args
{
	int	n_philos;
	int	t_to_die;
	int	t_to_sleep;
	int	t_to_eat;
	int	n_to_eat;
}	t_main_args;

typedef struct s_philo
{
	int				philo_number;
	int				t_to_die;
	int				t_to_sleep;
	int				t_to_eat;
	int				n_to_eat;
	int				n_times_ate;
	suseconds_t		start_time;
	suseconds_t		current_time;
	int				n_seconds_without_eating;
	int				state;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*displaying;
}	t_philo;

/*
** MACROS
*/

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define BASE_TEN "0123456789"
# define INT_MAX 2147483647
# define EATING 1
# define TOOK_A_FORK 2
# define THINKING 3
# define SLEEPING 4
# define DIED 5

/*
** PROTOTYPES
*/

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
void		ft_putendl_fd(char *str, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_puterr(char *str);
void		*ft_puterr_ptr(char *str);
char		*ft_strchr(char *str, int c);
char		*ft_strchrset(char *str, char *charset);
long		ft_atol(char *str);
int			ft_isnum(char c);
void		*ft_free(void *to_free, char *error_msg, void *to_return);
int			ft_free_int_ret(void *to_free, char *error_msg, int to_return);
void		*ft_malloc(int size, void **malloc_this);

t_main_args	*ft_new_main_args(void);
t_philo		*ft_initialize_philo(t_main_args *args, int n, t_philo **f);
int			ft_initialize_forks(t_philo *ph, int n, t_philo *prev, t_philo *f);

void		*ft_thread_function(void *arg);

int			ft_setup_start_time(t_philo *philo);
int			ft_get_current_time(t_philo *philo);
int			ft_msleep(int n_milliseconds);

int			ft_eat(t_philo *philo);
int			ft_sleep(t_philo *philo);
int			ft_think(t_philo *philo);

/*
** DEBUG
*/

void		ft_print_main_args(t_main_args *main_args);
void		ft_print_philo(t_philo	*philo, int with_mutex);

/*
** COLORS
*/

# define COLOR_RESET   "\x1b[0m"

# define BOLDRED "\033[1m\033[31m"
# define BOLDGREEN "\033[1m\033[32m"
# define BOLDYELLOW "\033[1m\033[33m"
# define BOLDBLUE "\033[1m\033[34m"
# define BOLDMAGENTA "\033[1m\033[35m"
# define BOLDCYAN "\033[1m\033[36m"
# define BOLDWHITE "\033[1m\033[37m"

#endif