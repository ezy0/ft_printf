/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:35:26 by migmoren          #+#    #+#             */
/*   Updated: 2022/11/13 21:02:56 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

static int	ft_format(char const *format, va_list arg)
{
	int	pr;

	pr = 0;
	if (*format == '%')
		pr += ft_putchar('%');
	else if (*format == 'c')
		pr += ft_putchar(va_arg(arg, int));
	else if (*format == 's')
		pr += ft_print_s(va_arg(arg, char const *));
	else if (*format == 'p')
		pr += ft_print_p(va_arg(arg, void *));
	else
		pr += ft_print_nbr(va_arg(arg, int), *format);
	return (pr);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		pr;

	va_start (arg, str);
	pr = 0;
	while (*str)
	{
		if (*str != '%')
			pr += ft_putchar(*str);
		else
			pr += ft_format(++str, arg);
		str++;
	}
	return (pr);
}
