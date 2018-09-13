/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:38:54 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/13 13:48:26 by ndriver          ###   ########.fr       */
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
	count = 0;
	s = (t_stacks *)malloc(sizeof(t_stacks));
	if (ac == 2)
		init_one(s, av[1]);
	else
	{
		i = ac - 1;
		ft_init(s, i);
		while (count < i)
		{
			temp = ft_itoa(ft_atoi(av[count + 1]));
			if (ft_strequ(av[count + 1], temp))
			{
				s->a[count] = ft_atoi(av[count + 1]);
				s->a_top++;
			}
			else
				error();
			count++;
			free(temp);
		}
	}
	normalize(s);
	algo2(s);
//	print_tab(s, 'a');
	return (0);
}
