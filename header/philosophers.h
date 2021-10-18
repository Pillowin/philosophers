/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:39:37 by agautier          #+#    #+#             */
/*   Updated: 2021/10/18 14:00:18 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdint.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE
}	t_bool;

typedef enum e_errcode
{
	ERR_ARGS_NB = 0,
	ERR_ARGS_NB_PHILO,
	ERR_ARGS_TTD,
	ERR_ARGS_TTE,
	ERR_ARGS_TTS,
	ERR_ARGS_NB_EAT,
	ERR_THREAD,
	ERR_JOIN
}	t_errcode;

typedef struct s_rules
{
	uint8_t		nb_philo;
	uint16_t	time_to_die;
	uint16_t	time_to_eat;
	uint16_t	time_to_sleep;
	uint8_t		nb_must_eat;
	uint64_t	start_time;
}	t_rules;

typedef struct s_philo
{
	t_rules		*rules;
	uint8_t		index;
	pthread_t	thread;
}	t_philo;

uint64_t	get_timestamp(void);
t_bool		print_error(t_errcode err);
t_bool		parse(int argc, char **argv, t_rules *philo);

void	philo_think(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);

#endif
