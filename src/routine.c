/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:39:20 by agautier          #+#    #+#             */
/*   Updated: 2021/10/21 15:59:15 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**	
**	TODO: check meal count
**	TODO: check return with watcher
*/
void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (TRUE)
	{
		if (!philo_think(philo) || !philo_eat(philo) || !philo_sleep(philo))
			return (NULL);
	}
	return (NULL);
}
