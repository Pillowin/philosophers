/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:42:03 by agautier          #+#    #+#             */
/*   Updated: 2021/10/19 11:21:24 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**
*/
void	philo_eat(t_philo *philo)
{
	print(&philo->rules->print, get_timestamp() - philo->rules->start_time,
		philo->index, "eating");
}
