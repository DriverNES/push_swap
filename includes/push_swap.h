/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:33:38 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/06 18:07:38 by ndriver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "..\libft\libft.h"

typedef struct	s_stacks
{
	int		*a;
	int		*b;
	int		*masterstack;
	int		a_top;
	int		b_top;

}			t_stacks;

void		ft_init(t_stacks *s, int size);
void		error(int i);
void		normalize(t_stacks *s);
int			is_sorted(t_stacks *s);
void		print_tab(t_stacks *s, char c);

#endif
