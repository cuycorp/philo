/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:57:14 by mcamaren          #+#    #+#             */
/*   Updated: 2025/07/29 18:57:16 by mcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <errno.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo	t_philo;
typedef struct s_table
{
	int					n_philos;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_to_die;
	int					max_meal;
	int					stop_routine;
	t_philo				*philo;
	struct timeval		start_time;
	pthread_mutex_t		time;
	pthread_mutex_t		print;
	pthread_mutex_t		routine;
	pthread_mutex_t		num_meal;
	pthread_mutex_t		last_meal_time;
}						t_table;
typedef struct s_philo
{
	int					id;
	int					nb_meal;
	int					last_meal_time;
	pthread_t			thread;
	pthread_mutex_t		fork;
	t_table				*table;
}						t_philo;

typedef enum e_philo_log
{
	THINK,
	SLEEP,
	EAT,
	FORK,
	DEAD,
}						t_philo_log;

/* CHECK_ARGUMENTS */
int						check_argument(int argc, char **argv);

/* TIME */
long long				get_time_ms(t_table *table);
long long				get_current_time(t_table *table);
// void					precise_usleep(long usec);
void					precise_usleep_interruptible(long usec, t_table *table);

/* INIT */
t_table					*ft_init_all(char **argv);

/* UTILS */
void					*ft_alloc_struct(size_t size);
long long				ft_atoi(const char *nptr);
void					*ft_memset(void *s, int c, size_t n);
void					ft_putstr_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
size_t					ft_strlen(const char *s);

/*THREADS*/
void					set_philos(t_table *table);
void					*philo_routine(void *input);

/* CLEAR_LEAKS*/
void					ft_free_philo(t_table **table);

/* PHILO_STATE */
void					philo_think(t_philo *philo);
void					philo_sleep(t_philo *philo);
void					philo_eat(t_philo *philo);
void					philo_fork(t_philo *philo);
/* void					philo_dead(t_philo *philo); */
int						philo_dead(t_philo *philo);
void					philo_log(t_philo *philo, t_philo_log log_type);

/* MONITOR_ROUTINE */
void					*monitor_routine(void *input);
bool					simulation_finished(t_table *table);
#endif
