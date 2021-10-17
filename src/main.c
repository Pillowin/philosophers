/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:38:53 by agautier          #+#    #+#             */
/*   Updated: 2021/10/17 13:38:52 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <errno.h>

/*
**	
**	TODO: check meal count
*/
void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (TRUE)
	{
		philo_think(philo);
		philo_eat(philo);
		philo_sleep(philo);
		usleep(1000000);
	}
	return (NULL);
}

/*
**
*/
int	main(int argc, char **argv)
{
	t_philo	philo;

	if (!parse(argc, argv, &philo.rules))
		return (EXIT_FAILURE);
	
	philo.index = 0;	// TODO: index start at 1

	if (pthread_create(philo.thread, NULL, &routine, &philo) != 0)
		return (EXIT_FAILURE + print_error(ERR_THREAD));

	philo.rules->start_time = get_timestamp();
	fprintf(stderr, "start_time = %llu\n", philo.rules->start_time);
	while (TRUE)
	{
		fprintf(stderr, "time = %llu\n", get_timestamp() - philo.rules->start_time);
		usleep(1000000);
	}

	if (pthread_join(*philo.thread, NULL) != 0)
		return (EXIT_FAILURE + print_error(ERR_JOIN));

	return (EXIT_SUCCESS);
}
