/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:20:51 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/16 13:54:26 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>

/*
** PROTOTYPES
*/

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_puterr(char *str);

char	*ft_strchr(char *str, int c);
char	*ft_strchrset(char *str, char *charset);

long	ft_atol(char *str);
int		ft_isnum(char c);

/*
** MACROS
*/

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define BASE_TEN "0123456789"
# define INT_MAX 2147483647

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

# endif