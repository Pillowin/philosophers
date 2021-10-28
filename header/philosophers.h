/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:39:37 by agautier          #+#    #+#             */
/*   Updated: 2021/10/28 12:34:26 by agautier         ###   ########.fr       */
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

typedef pthread_mutex_t	t_mutex;

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
	ERR_MALLOC,
	ERR_CREATE,
	ERR_JOIN,
	ERR_INIT,
	ERR_LOCK,
	ERR_UNLOCK,
	ERR_DESTROY
}	t_errcode;

typedef struct s_rules
{
	uint8_t		nb_philo;
	uint16_t	time_to_die;
	uint16_t	time_to_eat;
	uint16_t	time_to_sleep;
	uint8_t		nb_must_eat;
	uint8_t		ready;
	t_mutex		print;
	t_mutex		mut;
	t_bool		running;
}	t_rules;

typedef struct s_philo
{
	t_rules		*rules;
	uint8_t		index;
	pthread_t	thread;
	t_mutex		rfork;
	t_mutex		*lfork;
	uint64_t	time_last_eat;
	uint8_t		nb_meal;
	t_mutex		mut;
}	t_philo;

uint64_t	get_timestamp(void);
t_bool		print_error(t_rules *rules, t_errcode err);
t_bool		parse(int argc, char **argv, t_rules *philo);

t_bool		print(t_rules *rules, uint8_t index, char *action);
t_bool		philo_think(t_philo *philo);
t_bool		philo_eat(t_philo *philo);
t_bool		philo_sleep(t_philo *philo);
void		*routine(void *ptr);
t_bool		watcher(t_philo *philos);
t_bool		stop_running(t_rules *rules);
t_bool		get_running(t_rules *rules);

void		my_usleep(t_rules *rules, useconds_t us);

#endif
