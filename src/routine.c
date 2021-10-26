/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:39:20 by agautier          #+#    #+#             */
/*   Updated: 2021/10/26 15:52:02 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**	Wait for all philosophers to be ready to launch routine.
*/
static t_bool	wait_sync(t_rules *rules)
{
	if (pthread_mutex_lock(&rules->print) != 0)
		return (print_error(rules, ERR_LOCK));
	rules->ready += 1;
	if (pthread_mutex_unlock(&rules->print) != 0)
		return (print_error(rules, ERR_UNLOCK));
	while (TRUE)
	{
		if (pthread_mutex_lock(&rules->print) != 0)
			return (print_error(rules, ERR_LOCK));
		if (rules->ready == rules->nb_philo)
			break ;
		if (pthread_mutex_unlock(&rules->print) != 0)
			return (print_error(rules, ERR_UNLOCK));
	}
	if (pthread_mutex_unlock(&rules->print) != 0)
		return (print_error(rules, ERR_UNLOCK));
	return (TRUE);
}

/*
**	
**	TODO: check meal count
**	TODO: check return with watcher
*/
void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (!wait_sync(philo->rules))
		return (NULL);
	while (get_running(philo->rules))
		if (!philo_think(philo) || !philo_eat(philo) || !philo_sleep(philo))
			return (NULL);
	return (NULL);
}
