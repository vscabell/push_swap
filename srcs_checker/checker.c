/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:17:41 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/10 16:53:44 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_program(t_stacks *stacks)
{
	clear_stacks(*stacks);
	exit(EXIT_FAILURE);
}

static void	validate_args(int argc, char **argv)
{
	if (!validate_params(argc, argv))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

static void	build_stacks(int argc, char **argv, t_stacks *stacks)
{
	t_list	*new_node;

	stacks->a = (t_stack){0};
	stacks->b = (t_stack){0};
	while (stacks->a.size < argc - 1)
	{
		new_node = ft_lstnew((int)ft_atoi(argv[stacks->a.size + 1]));
		if (!new_node)
			exit_program(stacks);
		ft_lstadd_back(&stacks->a.head, new_node);
		(stacks->a.size)++;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	validate_args(argc, argv);
	build_stacks(argc, argv, &stacks);
	print_stacks(stacks);
	// operations("sa", &stacks);
	// operations("pb", &stacks);
	// operations("pb", &stacks);
	// operations("pb", &stacks);
	// print_stacks(stacks);
	clear_stacks(stacks);
	return (EXIT_SUCCESS);
}