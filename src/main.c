/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:38:53 by agautier          #+#    #+#             */
/*   Updated: 2021/10/18 14:03:03 by agautier         ###   ########.fr       */
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

/*
**
*/
int	main(int argc, char **argv)
{
	t_rules	rules;
	t_philo	philo;
	t_philo	philot;

	rules = (t_rules){0, 0, 0, 0, 0, 0};
	if (!parse(argc, argv, &rules))
		return (EXIT_FAILURE);
	
//	philo.rules = &rules;
//	philot.rules = &rules;

	philo.index = 1;
	philot.index = 2;

	if (pthread_create(&philo.thread, NULL, &routine, &philo) != 0)
		return (EXIT_FAILURE + print_error(ERR_THREAD));
	if (pthread_create(&philot.thread, NULL, &routine, &philot) != 0)
		return (EXIT_FAILURE + print_error(ERR_THREAD));

	rules.start_time = get_timestamp();
	fprintf(stderr, "start_time = %llu\n", rules.start_time);
	while (TRUE)
	{
		fprintf(stderr, "time = %llu\n", get_timestamp() - rules.start_time);
		usleep(100000);
	}

	if (pthread_join(philo.thread, NULL) != 0)
		return (EXIT_FAILURE + print_error(ERR_JOIN));
	if (pthread_join(philot.thread, NULL) != 0)
		return (EXIT_FAILURE + print_error(ERR_JOIN));

	return (EXIT_SUCCESS);
}
