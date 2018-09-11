/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 11:13:20 by ndriver           #+#    #+#             */
/*   Updated: 2018/07/16 12:26:37 by ndriver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	int		len;
	char	**stra;
	int		i;
	int		wc;

	if (!s)
		return (NULL);
	wc = ft_cntwrd(s, c);
	len = 0;
	stra = (char **)ft_memalloc((wc + 1) * sizeof(char *));
	if (!stra)
		return (NULL);
	i = 0;
	len = 0;
	while (*s)
	{
		len = ft_find_word(s, c, stra, i++);
		s += len;
	}
	stra[wc] = 0;
	return (stra);
}
