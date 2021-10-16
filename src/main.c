/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:38:53 by agautier          #+#    #+#             */
/*   Updated: 2021/10/17 00:58:29 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**	
**	TODO: check meal count
*/
void	*routine(void *ptr)
{
	(void)ptr;

	t_state	state;

	state = THINK;
	while (state != EXIT)
	{
		if (state == THINK)
		{
			philo_think();
			state = EAT;
		}
		if (state == EAT)
		{
			philo_eat();
			state = SLEEP;
		}
		if (state == SLEEP)
		{
			philo_sleep();
			state = THINK;
		}
	}
	return (NULL);
}

/*
**
*/
int	main(int argc, char **argv)
{
	t_rules	rules;

	if (!parse(argc, argv, &rules))
		return (EXIT_FAILURE);

	fprintf(stderr, "rules.nb_philo = %u\n", rules.nb_philo);
	fprintf(stderr, "rules.nb_must_eat = %u\n", rules.nb_must_eat);
	fprintf(stderr, "rules.time_to_die = %u\n", rules.time_to_die);
	fprintf(stderr, "rules.time_to_eat = %u\n", rules.time_to_eat);
	fprintf(stderr, "rules.time_to_sleep = %u\n", rules.time_to_sleep);
	fprintf(stderr, "rules.nb_must_eat = %u\n", rules.nb_must_eat);

	rules.start_time = get_timestamp();
//	while (1)
//	{
//		fprintf(stderr, "start_time = %llu\n", get_timestamp() - philo.start_time);
//		usleep(5000);
//	}
	routine(NULL);
	return (EXIT_SUCCESS);
}
