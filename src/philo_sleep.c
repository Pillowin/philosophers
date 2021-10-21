/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:42:23 by agautier          #+#    #+#             */
/*   Updated: 2021/10/21 16:21:43 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**	Print sleeping message and sleep time_to_sleep ms.
*/
t_bool	philo_sleep(t_philo *philo)
{
	print(philo->rules, philo->index, "is sleeping");
	usleep(philo->rules->time_to_sleep * 1000);
	return (TRUE);
}
