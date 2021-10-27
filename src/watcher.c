/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:08:57 by agautier          #+#    #+#             */
/*   Updated: 2021/10/27 19:20:18 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**	Return curr state of rules->running.
*/
t_bool	get_running(t_rules *rules)
{
	if (pthread_mutex_lock(&rules->mut) != 0)
		return (print_error(rules, ERR_LOCK));
	if (rules->running == FALSE)
	{
		if (pthread_mutex_unlock(&rules->mut) != 0)
			return (print_error(rules, ERR_UNLOCK));
		return (FALSE);
	}
	if (pthread_mutex_unlock(&rules->mut) != 0)
		return (print_error(rules, ERR_UNLOCK));
	return (TRUE);
}

/*
**	Change state of rules->running to FALSE.
*/
t_bool	stop_running(t_rules *rules)
{
	if (pthread_mutex_lock(&rules->mut) != 0)
		return (print_error(rules, ERR_LOCK));
	rules->running = FALSE;
	if (pthread_mutex_unlock(&rules->mut) != 0)
		return (print_error(rules, ERR_UNLOCK));
	return (TRUE);
}

/*
**	Checks if a philosoper is dead or if an error occured.
*/
t_bool	watcher(t_philo *philos)
{
	uint8_t	i;

	i = 0;
	while (get_running(philos->rules) && i < philos->rules->nb_philo)
	{
		if (pthread_mutex_lock(&(philos[i]).mut) != 0)
			return (print_error(philos->rules, ERR_LOCK));
		if (philos[i].time_last_eat + philos->rules->time_to_die
			<= get_timestamp())
		{
			if (pthread_mutex_unlock(&(philos[i]).mut) != 0)
				return (print_error(philos->rules, ERR_UNLOCK));
			print(philos[i].rules, philos[i].index, "died");
			fprintf(stderr, "index = %u\nlast eat = %llu\nttd = %hu\ncurr time = %llu\n", philos[i].index, philos[i].time_last_eat, (*philos).rules->time_to_die, get_timestamp());
			stop_running(philos->rules);
			return (FALSE);
		}
		if (pthread_mutex_unlock(&(philos[i]).mut) != 0)
			return (print_error(philos->rules, ERR_UNLOCK));
		i += 1;
	}
	return (TRUE);
}
