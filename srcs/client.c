/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:23:44 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/25 12:18:18 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

static void	ft_reception(int signum)
{
	if (signum == SIGUSR1)
		g_finish_flag = 0;
	if (signum == SIGUSR2)
		exit(ft_printf("Message received\n"));
}

static void	ft_send_1_char(int pid, char c)
{
	int	i;
	int	res_kill;

	i = 0;
	res_kill = 0;
	while (i < 8)
	{
		if (c & 1)
			res_kill = kill(pid, SIGUSR1);
		else
			res_kill = kill(pid, SIGUSR2);
		if (res_kill == -1)
		{
			ft_printf("Le signal n'a pas pu etre recu, verifier le PID\n");
			exit(0);
		}
		c >>= 1;
		usleep(400);
		i++;
		while (g_finish_flag)
			sleep(1);
		g_finish_flag = 1;
	}
}

static void	ft_send_string(int pid, char *message)
{
	int	i;

	i = 0;
	while (message && message[i])
	{
		ft_send_1_char(pid, message[i]);
		i++;
	}
	ft_send_1_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*message;
	struct sigaction	sig_server;

	if (argc != 3)
	{
		ft_printf("Program needs 2 argument : PID, STRING TO PASS\n");
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 1)
		return (ft_printf("Invalid PID !\n"), -1);
	message = argv[2];
	sigemptyset(&sig_server.sa_mask);
	sig_server.sa_flags = SA_SIGINFO;
	sig_server.sa_handler = &ft_reception;
	if (sigaction(SIGUSR1, &sig_server, NULL) < 0)
		exit(1);
	if (sigaction(SIGUSR2, &sig_server, NULL) < 0)
		exit(1);
	ft_send_string(pid, message);
	return (0);
}
