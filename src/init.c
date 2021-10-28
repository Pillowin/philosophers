/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:42:23 by agautier          #+#    #+#             */
/*   Updated: 2021/10/28 14:06:36 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**	Init philos.
*/
t_bool	init_philos(t_rules *rules, t_philo **philos)
{
	uint8_t	i;

	*philos = (t_philo *)malloc(sizeof(t_philo) * rules->nb_philo);
	if (!*philos)
		return (print_error(rules, ERR_MALLOC));
	i = 1;
	while (i <= rules->nb_philo)
	{
		(*philos)[i - 1] = (t_philo){rules, i, NULL, {0}, NULL, 0, 0, {0}};
		i += 1;
	}
	return (TRUE);
}

/*
**	Init forks.
*/
t_bool	init_forks(t_philo *philos)
{
	uint8_t	i;

	i = 1;
	while (i <= philos->rules->nb_philo)
	{
		if (i > 1)
			philos[i - 2].lfork = &philos[i - 1].rfork;
		if (pthread_mutex_init(&philos[i - 1].rfork, NULL) != 0)
			return (print_error(philos->rules, ERR_INIT));
		if (pthread_mutex_init(&philos[i - 1].mut, NULL) != 0)
			return (print_error(philos->rules, ERR_INIT));
		i += 1;
	}
	philos[i - 2].lfork = &philos[0].rfork;
	return (TRUE);
}

/*
**	Init mutexes.
*/
t_bool	init_mutex(t_philo *philos)
{
	if (pthread_mutex_init(&philos->rules->print, NULL) != 0)
		return (print_error(philos->rules, ERR_INIT));
	if (pthread_mutex_init(&philos->rules->mut, NULL) != 0)
		return (print_error(philos->rules, ERR_INIT));
	return (TRUE);
}
