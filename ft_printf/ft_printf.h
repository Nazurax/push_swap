/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:16:08 by alortiz-          #+#    #+#             */
/*   Updated: 2025/01/17 10:16:18 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(char const *str, ...);
void	ft_putc(char c, size_t *count);
void	ft_putid(int nb, size_t *count);
void	ft_puts(char *str, size_t *count);
void	ft_putp(void *ptr, size_t *count);
void	ft_putu(unsigned int num, size_t *count);
void	bzero_p(void *str, size_t n);
char	*calloc_p(size_t num, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_utoa_base(unsigned long long num, char *base);
char	*ft_handlezero(void);
char	*ft_utoa(unsigned int num);
void	ft_puthex(unsigned int num, size_t *count, char *base);
void	ft_putstr_fd(char *s, int fd);

#endif
