/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:11:10 by agautier          #+#    #+#             */
/*   Updated: 2021/10/15 14:28:31 by agautier         ###   ########.fr       */
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
