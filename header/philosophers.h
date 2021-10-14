/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:39:37 by agautier          #+#    #+#             */
/*   Updated: 2021/10/14 20:17:20 by agautier         ###   ########.fr       */
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
	ERR_ARGS = 0
}	t_errcode;

typedef struct s_philo
{
	uint8_t		nb_philo;
	uint16_t	time_to_die;
	uint16_t	time_to_eat;
	uint16_t	time_to_sleep;
	uint8_t		nb_must_eat;
}	t_philo;

uint64_t	get_timestamp(void);
t_bool		print_error(t_errcode err);
t_bool		parse(int argc, char **argv);

#endif
