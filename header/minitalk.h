/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:23:29 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/13 15:13:05 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# ifndef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE 199309L
# endif 
# ifndef _DEFAULT_SOURCE
#  define _DEFAULT_SOURCE
# endif

# include "libft.h"
# include <signal.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

static int	g_finish_flag = 1;

#endif