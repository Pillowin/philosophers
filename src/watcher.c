/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:08:57 by agautier          #+#    #+#             */
/*   Updated: 2021/10/28 18:25:05 by agautier         ###   ########.fr       */
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
**	Checks if simulation should be stopped because of number of meals.
*/
static t_bool	check_nb_meal(t_philo *philos)
{
	uint8_t	i;
	uint8_t	philo_finished_eating;

	philo_finished_eating = 0;
	i = 0;
	while (get_running(philos->rules) && i < philos->rules->nb_philo)
	{
		if (pthread_mutex_lock(&(philos[i]).mut) != 0)
			return (print_error(philos->rules, ERR_LOCK));
		if (philos[i].nb_meal >= philos->rules->nb_must_eat)
			philo_finished_eating += 1;
		if (philo_finished_eating == philos->rules->nb_philo)
		{
			if (pthread_mutex_unlock(&(philos[i]).mut) != 0)
				return (print_error(philos->rules, ERR_UNLOCK));
			stop_running(philos->rules);
			return (FALSE);
		}
		if (pthread_mutex_unlock(&(philos[i]).mut) != 0)
			return (print_error(philos->rules, ERR_UNLOCK));
		i += 1;
	}
	return (TRUE);
}

/*
**	Checks if simulation should be stopped because a philo starved.
*/
static t_bool	check_died(t_philo *philos)
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
			stop_running(philos->rules);
			return (FALSE);
		}
		if (pthread_mutex_unlock(&(philos[i]).mut) != 0)
			return (print_error(philos->rules, ERR_UNLOCK));
		i += 1;
	}
	return (TRUE);
}

/*
**	Checks if a philosoper is dead or if an error occured.
*/
t_bool	watcher(t_philo *philos)
{
	if (!check_nb_meal(philos))
		return (FALSE);
	if (!check_died(philos))
		return (FALSE);
	return (TRUE);
}
