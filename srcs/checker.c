/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:55:39 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/18 11:27:01 by ndriver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int		main(int ac, char **av)
{
	t_stacks	s;
	char		**line;
	int			count;
	char		*temp;

	count = -1;
	line = malloc(10);
	*line = malloc(10);
	if (ac == 2)
		init_one(&s, av[1]);
	else
	{
		ft_init(&s, ac - 1);
		while (++count < s.size)
		{
			temp = ft_itoa(ft_atoi(av[ac - 1 - count]));
			set_one(&s, temp, av[ac - 1 - count], count);
			free(temp);
		}
	}
	normalize(&s);
	while (get_next_line(0, line) > 0)
		func(&s, *line);
	checker(&s);
	exit(0);
}
