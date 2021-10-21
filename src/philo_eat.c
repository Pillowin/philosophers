/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:42:03 by agautier          #+#    #+#             */
/*   Updated: 2021/10/21 16:42:13 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**	Print eating message and sleep time_to_eat ms.
*/
t_bool	philo_eat(t_philo *philo)
{
	print(philo->rules, philo->index, "is eating");
	usleep(philo->rules->time_to_eat * 1000);
	if (pthread_mutex_unlock(philo->lfork) != 0)
		return (print_error(ERR_UNLOCK));
	if (pthread_mutex_unlock(&philo->rfork) != 0)
		return (print_error(ERR_UNLOCK));
	return (TRUE);
}
