/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:11:30 by gnicolo           #+#    #+#             */
/*   Updated: 2025/02/04 11:03:37 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <limits.h>
#include <unistd.h>

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	char	nbr;
	int		i;

	i = 1;
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
		i = 3;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		i = 2;
		nb = -nb;
	}
	if (nb >= 10)
		i += ft_putnbr(nb / 10);
	nbr = (nb % 10) + 48;
	write(1, &nbr, 1);
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_u(unsigned int nb)
{
	char	nbr;
	int		i;

	i = 1;
	if (nb >= 10)
		i += ft_putnbr_u(nb / 10);
	nbr = (nb % 10) + 48;
	write(1, &nbr, 1);
	return (i);
}

int	ft_pointer(uintptr_t exa)
{
	int		i;

	i = 2;
	if (!exa)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	ft_putstr("0x");
	i += ft_exa_low_two(exa);
	return (i);
}
/* int main (void)
{
	int m, i;
	char *jh;

	i = printf("jfrgwgui%p\nguihgfy", LONG_MIN);
	printf("%d\n", i);	m = ft_printf("%p\n", LONG_MIN);

	printf("%d\n", m);
	return (0);
}
 */
