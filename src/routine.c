/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:39:20 by agautier          #+#    #+#             */
/*   Updated: 2021/10/18 14:39:31 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**	
**	TODO: check meal count
*/
void	*routine(void *ptr)
{
	t_philo	*phi;

	phi = (t_philo *)ptr;
	while (TRUE)
	{
		fprintf(stderr, "%u\t\t", phi->index);
		philo_think(phi);

		fprintf(stderr, "%u\t\t", phi->index);
		philo_eat(phi);

		fprintf(stderr, "%u\t\t", phi->index);
		philo_sleep(phi);

		usleep(1000000);
	}
	return (NULL);
}
