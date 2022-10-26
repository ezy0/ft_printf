/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:35:26 by migmoren          #+#    #+#             */
/*   Updated: 2022/10/26 17:57:14 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

static int	ft_format(const char *format, va_list arg)
{
	int	pr;

	pr = 0;
	if (*format == '%')
		pr += ft_putchar('%');
	else if (*format == 'c')
		pr += ft_putchar(format[0]);
	else if (*format == 's')
		pr += ft_print_s(va_arg(arg, char *));
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
		if (*str == '%')
			pr += ft_format((str++) + 1, arg);
		else
			pr += ft_putchar(*str);
		str++;
	}
	return (pr);
}
