/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:24:55 by lucasu            #+#    #+#             */
/*   Updated: 2024/12/03 16:51:15 by lucasu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}
