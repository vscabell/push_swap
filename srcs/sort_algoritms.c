/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:12:45 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/15 03:40:34 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_operation(char *op, t_stacks *stacks)
{
	operations(op, stacks);
	ft_printf("%s\n", op);
}

//............................... //
//        INSERTION SORT          //
//.............................. .//

size_t	get_posit_min_value(t_stack *a)
{
	t_list		*tmp;
	int			min;
	size_t		posit;
	size_t		i;

	i = 0;
	posit = 0;
	min = 2147483647;
	tmp = a->head;
	while (tmp)
	{
		if (tmp->numb < min)
		{
			min = tmp->numb;
			posit = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (posit);
}

void	push_min_value_to_top_of_stack(t_stacks *stacks, size_t posit)
{
	size_t	i;

	i = 0;
	while (i < posit)
	{
		call_operation("ra", stacks);
		i++;
	}
}

void	insertion_sort(t_stacks *stacks)
{
	size_t	posit;
	size_t	size;

	size = ft_lstsize(stacks->a.head);
	while (size > 0)
	{
		posit = get_posit_min_value(&stacks->a);
		push_min_value_to_top_of_stack(stacks, posit);
		call_operation("pb", stacks);
		size--;
	}
	size = ft_lstsize(stacks->b.head);
	while (size > 0)
	{
		call_operation("pa", stacks);
		size--;
	}
}

//............................... //
//       SORT LIST OF TREE        //
//.............................. .//

void	atribute_args(t_list *lst, int *args)
{
	args[POS_0] = lst->numb;
	args[POS_1] = lst->next->numb;
	args[POS_2] = lst->next->next->numb;
}

void	get_posit(t_list *lst, t_three *posit)
{
	int	args[3];
	int	min;
	int	max;
	int	i;

	atribute_args(lst, &args);
	i = 0;
	min = 2147483647;
	max = -2147483648;
	while (i < 3)
	{
		if (args[i] <= min)
		{
			min = args[i];
			posit->min = i;
		}
		if (args[i] >= max)
		{
			max = args[i];
			posit->max = i;
		}
		i++;
	}
	if (posit->min != POS_1 && posit->max != POS_1)
		posit->mid = POS_1;
	else if (posit->min != POS_2 && posit->max != POS_2)
		posit->mid = POS_2;
	else
		posit->mid = POS_0;
}

void	sort_list_of_tree_a(t_stacks *stacks)
{
	t_three	posit;

	if (stacks->a.size < 3)
		return ;
	get_posit(stacks->a.head, &posit);
	if (posit.min == POS_0 && posit.mid == POS_2 && posit.max == POS_1)
	{
		call_operation("sa", stacks);
		call_operation("ra", stacks);
	}
	else if (posit.min == POS_1 && posit.mid == POS_0 && posit.max == POS_2)
		call_operation("sa", stacks);
	else if (posit.min == POS_1 && posit.mid == POS_2 && posit.max == POS_0)
		call_operation("ra", stacks);
	else if (posit.min == POS_2 && posit.mid == POS_1 && posit.max == POS_0)
	{
		call_operation("sa", stacks);
		call_operation("rra", stacks);
	}
	else if (posit.min == POS_2 && posit.mid == POS_0 && posit.max == POS_1)
		call_operation("rra", stacks);
}

void	sort_list_of_tree(t_stacks *stacks)
{
	sort_list_of_tree_a(stacks);
}
