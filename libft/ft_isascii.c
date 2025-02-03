/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:51:18 by lucasu            #+#    #+#             */
/*   Updated: 2024/11/25 11:51:20 by lucasu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	int	res;

	res = 0;
	if (c >= 0 && c <= 127)
	{
		res = 1;
	}
	return (res);
}
