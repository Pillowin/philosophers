/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:42:03 by agautier          #+#    #+#             */
/*   Updated: 2021/10/18 14:43:40 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**
*/
void	philo_eat(t_philo *philo)
{
	printf("%llu\t%u is eating\n",
		get_timestamp() - philo->rules->start_time, philo->index);
}
