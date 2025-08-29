/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:46:30 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/25 11:20:19 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

static void	ft_print_and_send_receipt(char *message, siginfo_t *info)
{
	ft_printf("%s\n", message);
	g_finish_flag = 1;
	kill(info->si_pid, SIGUSR2);
}

static void	ft_is_it_an_exit(char *message)
{
	if (message && !ft_strncmp(message, "EXIT", 5))
	{
		free(message);
		exit(0);
	}
	if (message)
		free(message);
	return ;
}

static char	*ft_append(char *message, char *c)
{
	char	*tmp;

	tmp = message;
	message = ft_strjoin(message, c);
	if (tmp)
		free(tmp);
	return (message);
}

static void	ft_receive_bits(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 0;
	static char	*message = NULL;

	if (signum == SIGUSR1)
		c |= (1 << i);
	i ++;
	if (i == 8)
	{
		i = 0;
		if (c == 0)
		{
			ft_print_and_send_receipt(message, info);
			ft_is_it_an_exit(message);
			return ((void)(message = NULL));
		}
		message = ft_append(message, &c);
		if (!message)
			return ((void)ft_printf("Malloc error \n"));
		c = 0;
	}
	(kill(info->si_pid, SIGUSR1), (void)context);
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("PID : %d\n", getpid());
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &ft_receive_bits;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
		pause();
	return (0);
}
