/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:48:38 by fsalomon          #+#    #+#             */
/*   Updated: 2024/03/29 11:11:38 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_free_and_null_or_alloc(char *str, char *str2, int flags);
char	*ft_strjoin_gnl(char *stack, char *buffer);
int		ft_there_is_lf_or_strlen(char *s, int flags);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_how_many_bytes_for_line(char *s);
char	*ft_optimise_memmove(void *dest, const void *src, size_t n, size_t i);
char	*ft_change_stack_adress(char *stack, int stack_len, int line_len);
char	*ft_read_next_line(char *buffer, char *stack, int fd);
char	*ft_stack_init(char *stack, char *line, int line_len);
void	handle_malloc_erroc(void *to_free1, void *to_free2, void *to_free3);
#endif