/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcrius <kcrius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:31:04 by kcrius            #+#    #+#             */
/*   Updated: 2022/07/05 20:31:06 by kcrius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <semaphore.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <signal.h>
# define PHIL_NB 0
# define DIE_TIME 1
# define EAT_TIME 2
# define SLEEP_TIME 3
# define EAT_TIMES 4
# define SEM_STDOUT "stdout"
# define SEM_FORKS "forks"
# define SEM_LAST "last_eat"

typedef struct s_phil_process
{
	int				number;
	char			*name;
	pid_t			pid;
	void			*data;
	int				eat_times;
	int				has_eaten;
	unsigned long	last_eat;
	int				is_dead;
	sem_t			*last_eating;
	pthread_t		thread;
}	t_phil_process;
typedef struct s_data
{
	int				eat_all;
	unsigned long	start;
	int				input_data[6];
	t_phil_process	*phil_process;
	sem_t			*forks;
	sem_t			*std_out;
}	t_data;
void			ft_putstr(char *s);
int				error(char *s);
int				initializer(t_data *data, char **av, int ac);
int				act(t_phil_process *phil_process);
int				print_act(char *s, t_phil_process *pprocess, int isdead);
void			print_unsigned_number(unsigned long int num, int base, char x);
unsigned long	get_time_to_mls(void);
void			clean_all_malloc(t_data *data);
void			clean_all(t_data *data);
char			*ft_itoa(int n);
int				ft_strlen(const char *s);
sem_t			*creat_sem(char *name, int value);
#endif