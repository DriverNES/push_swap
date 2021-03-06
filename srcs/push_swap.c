/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:38:54 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/18 10:02:42 by ndriver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int ac, char **av)
{
	int			i;
	int			count;
	t_stacks	*s;
	char		*temp;

	i = 0;
	count = -1;
	s = (t_stacks *)malloc(sizeof(t_stacks));
	if (ac == 2)
		init_one(s, av[1]);
	else
	{
		i = ac - 1;
		ft_init(s, i);
		while (++count < s->size)
		{
			temp = ft_itoa(ft_atoi(av[i]));
			set_one(s, temp, av[i], count);
			i--;
			free(temp);
		}
	}
	normalize(s);
	algo2(s);
	return (0);
}
