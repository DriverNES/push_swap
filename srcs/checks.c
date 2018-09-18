/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:44:19 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/18 09:58:27 by ndriver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int		is_sorted(t_stacks *s)
{
	int i;
	int j;

	i = 0;
	while (i <= s->a_top)
	{
		j = i + 1;
		while (j <= s->a_top)
		{
			if (s->a[i] < s->a[j] && j <= s->a_top)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_dupes(t_stacks *s)
{
	int i;
	int j;

	i = 0;
	while (i <= s->a_top)
	{
		j = i;
		j++;
		while (j <= s->a_top)
		{
			if (s->a[j] == s->a[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	checker(t_stacks *s)
{
	if (check_dupes(s))
		error();
	if (is_sorted(s))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
