/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:43:55 by agautier          #+#    #+#             */
/*   Updated: 2021/10/28 14:04:07 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**	Clean exit of simulation.
*/
t_bool	destroy(t_philo *philos, t_destroy destroy)
{
	uint8_t	i;

	i = 0;
	while (destroy == ALL && i < philos->rules->nb_philo)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (print_error(philos->rules, ERR_JOIN));
		i += 1;
	}
	i = 0;
	while (destroy >= FORKS && i < philos->rules->nb_philo)
	{
		if (pthread_mutex_destroy(&(philos[i].rfork)) != 0)
			return (print_error(philos->rules, ERR_DESTROY));
		if (pthread_mutex_destroy(&(philos[i].mut)) != 0)
			return (print_error(philos->rules, ERR_DESTROY));
		i += 1;
	}
	if (destroy >= MUTEXES && pthread_mutex_destroy(&philos->rules->print) != 0)
		return (print_error(philos->rules, ERR_DESTROY));
	if (destroy >= MUTEXES && pthread_mutex_destroy(&philos->rules->mut) != 0)
		return (print_error(philos->rules, ERR_DESTROY));
	if (destroy >= PHILOS)
		free(philos);
	return (TRUE);
}
