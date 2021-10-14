/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:11:10 by agautier          #+#    #+#             */
/*   Updated: 2021/10/14 20:12:54 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**	Custom implementation of strlen.
*/
static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
**	Print str followed by \n on fd.
*/
static void	putendl_fd(const char *str, int fd)
{
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
}

/*
**	Return message corresponding with errcode.
*/
static const char	*get_errmsg(t_errcode err)
{
	if (err == ERR_ARGS)
		return ("Bad number of arguments.\nUse ./philosophers \
number_of_philosophers time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat].");
	return ("Unknown error.");
}

/*
**	Print str on STDERR_FILENO and return FALSE.
*/
t_bool	print_error(t_errcode err)
{
	putendl_fd(get_errmsg(err), STDERR_FILENO);
	return (FALSE);
}
