/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:38:53 by agautier          #+#    #+#             */
/*   Updated: 2021/10/15 15:27:44 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**
*/
int	main(int argc, char **argv)
{
	t_philo		philo;

	if (!parse(argc, argv, &philo))
		return (EXIT_FAILURE);

	fprintf(stderr, "philo.nb_philo = %u\n", philo.nb_philo);
	fprintf(stderr, "philo.nb_must_eat = %u\n", philo.nb_must_eat);
	fprintf(stderr, "philo.time_to_die = %u\n", philo.time_to_die);
	fprintf(stderr, "philo.time_to_eat = %u\n", philo.time_to_eat);
	fprintf(stderr, "philo.time_to_sleep = %u\n", philo.time_to_sleep);
	fprintf(stderr, "philo.nb_must_eat = %u\n", philo.nb_must_eat);

	philo.start_time = get_timestamp();
	while (1)
	{
		fprintf(stderr, "start_time = %llu\n", get_timestamp() - philo.start_time);
		usleep(500);
	}
	return (EXIT_SUCCESS);
}
