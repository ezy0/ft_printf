/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:24:38 by migmoren          #+#    #+#             */
/*   Updated: 2022/11/13 13:54:56 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_putchar(char c);
int	ft_printf(char const *str, ...);
int	ft_print_s(char const *str);
int	ft_print_p(void *ptr);
int	ft_print_nbr(int num, char format);

#endif	