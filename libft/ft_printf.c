/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:57:23 by gnicolo           #+#    #+#             */
/*   Updated: 2025/01/20 12:19:14 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_exa_low(unsigned int exa)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (exa >= 16)
		i += ft_exa_low(exa / 16);
	i += ft_putchar(base[(exa % 16)]);
	return (i);
}

int	ft_exa_up(unsigned int exa)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789ABCDEF";
	if (exa >= 16)
		i += ft_exa_up(exa / 16);
	i += ft_putchar(base[(exa % 16)]);
	return (i);
}

int	ft_check_char(char c, va_list params)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(params, int));
	else if (c == 's')
		count += ft_putstr(va_arg(params, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(params, int));
	else if (c == 'u')
		count += ft_putnbr_u(va_arg(params, unsigned int));
	else if (c == '%')
		count += ft_putchar(37);
	else if (c == 'p')
		count += ft_pointer(va_arg(params, uintptr_t));
	else if (c == 'x')
		count += ft_exa_low(va_arg(params, unsigned long));
	else if (c == 'X')
		count += ft_exa_up(va_arg(params, unsigned long));
	else
		return (0);
	return (count);
}

int	ft_exa_low_two(unsigned long exa)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (exa >= 16)
		i += ft_exa_low_two(exa / 16);
	i += ft_putchar(base[(exa % 16)]);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	va_start(params, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_check_char(str[i], params);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(params);
	return (count);
}
