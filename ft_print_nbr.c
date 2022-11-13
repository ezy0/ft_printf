/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:20:18 by migmoren          #+#    #+#             */
/*   Updated: 2022/11/13 14:09:26 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_base(int num, char *base)
{
	int	len;

	len = 1;
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		ft_putchar('-');
		len += ft_base(num * -1, base);
	}
	else if (num >= ft_strlen(base))
	{
		len += ft_base(num / ft_strlen(base), base);
		ft_putchar(base[num % ft_strlen(base)]);
	}
	else
		ft_putchar(base[num]);
	return (len);
}

static int	ft_u(unsigned int num, char *base)
{
	unsigned int	len;

	len = 1;
	if (num < 0)
	{
		ft_putchar('-');
		len += ft_base(num * -1, base);
	}
	else if (num >= (unsigned int)ft_strlen(base))
	{
		len += ft_base(num / ft_strlen(base), base);
		ft_putchar(base[num % ft_strlen(base)]);
	}
	else
		ft_putchar(base[num]);
	return (len);
}

int	ft_print_nbr(int num, char format)
{
	char	*hex_min;
	char	*hex_upp;
	char	*dec;

	hex_min = "0123456789abcdef";
	hex_upp = "0123456789ABCDEF";
	dec = "0123456789";
	if (format == 'd')
		return (ft_base(num, dec));
	if (format == 'i')
		return (ft_base(num, dec));
	if (format == 'u')
		return (ft_u(num, dec));
	if (format == 'x')
		return (ft_base(num, hex_min));
	if (format == 'X')
		return (ft_base(num, hex_upp));
	return (1);
}
