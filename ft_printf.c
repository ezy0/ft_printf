/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:35:26 by migmoren          #+#    #+#             */
/*   Updated: 2022/10/25 19:52:16 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_format(char *format, va_list arg)
{
	va_start (arg, )
	if (*format == 'c')

	else if (*format == 's')

	else if (*format == '%')
			write (1, "%", 1);
	else
		return ;
}

/*int	ft_printf(char const *str, ...)
{

}*/
