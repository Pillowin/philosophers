/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:42:23 by agautier          #+#    #+#             */
/*   Updated: 2021/10/19 11:26:25 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**
*/
void	philo_sleep(t_philo *philo)
{
	print(&philo->rules->print, get_timestamp() - philo->rules->start_time, philo->index, "sleeping");
}
