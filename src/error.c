/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:11:10 by agautier          #+#    #+#             */
/*   Updated: 2021/10/21 16:42:58 by agautier         ###   ########.fr       */
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
**	Continuation of the function bellow.
*/
static const char	*get_errmsg_2(t_errcode err)
{
	if (err == ERR_LOCK)
		return ("Cannot lock mutex.");
	else if (err == ERR_UNLOCK)
		return ("Cannot unlock mutex.");
	else if (err == ERR_DESTROY)
		return ("Cannot destroy mutex.");
	return ("Unknown error.");
}

/*
**	Return message corresponding with errcode.
*/
static const char	*get_errmsg(t_errcode err)
{
	if (err == ERR_ARGS_NB)
		return ("Bad number of arguments.\nUse ./philosophers \
number_of_philosophers time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat].");
	else if (err == ERR_ARGS_NB_PHILO)
		return ("Invalid number of philosophers. Should be between 0 and 255.");
	else if (err == ERR_ARGS_TTD)
		return ("Invalid time to die. Should be between 0 and 65535.");
	else if (err == ERR_ARGS_TTE)
		return ("Invalid time to eat. Should be between 0 and 65535.");
	else if (err == ERR_ARGS_TTS)
		return ("Invalid time to sleep. Should be between 0 and 65535.");
	else if (err == ERR_ARGS_NB_EAT)
		return ("Invalid number of times each philosophers must eat. \
Should be between 0 and 255.");
	else if (err == ERR_MALLOC)
		return ("Cannot allocate memory.");
	else if (err == ERR_CREATE)
		return ("Cannot create thread.");
	else if (err == ERR_JOIN)
		return ("Cannot join thread.");
	else if (err == ERR_INIT)
		return ("Cannot init mutex.");
	return (get_errmsg_2(err));
}

/*
**	Print str on STDERR_FILENO and return FALSE.
*/
t_bool	print_error(t_errcode err)
{
	putendl_fd(get_errmsg(err), STDERR_FILENO);
	return (FALSE);
}
