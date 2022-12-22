#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*final;
	char	*str;
	char	pipe;

	if (argc < 2)
		return (0);
	if (argc == 2 && !ft_strlen(argv[1]))
		return (0);
	final = malloc(sizeof(t_stack));
	if (!final)
		return (0);
	init_stacks(final);
	process_args(argc, argv, final);
	pipe = 0;
	str = get_next_line(0);
	if (str)
		pipe = 1;
	else
		str = get_next_line(1);
	while (str)
	{
		if (!(ft_strncmp("sa\n", str, 4)))
			swap(final->a[0], final->a[1]);
		else if (!(ft_strncmp("sb\n", str, 4)))
			swap(final->b[final->a_size - final->curr_b_size], \
				final->b[final->a_size - final->curr_b_size + 1]);
		else if (!(ft_strncmp("pa\n", str, 4)))
			pa(final);
		else if (!(ft_strncmp("pb\n", str, 4)))
			pb(final);
		else if (!(ft_strncmp("ra\n", str, 4)))
			rot(final, 'a', final->a, final->curr_a_size);
		else if (!(ft_strncmp("rb\n", str, 4)))
			rot(final, 'b', final->b, final->curr_b_size);
		else if (!(ft_strncmp("rra\n", str, 4)))
			rev_rot(final, 'a', final->a, final->curr_a_size);
		else if (!(ft_strncmp("rrb\n", str, 4)))
			rev_rot(final, 'b', final->b, final->curr_b_size);
		else if (!(ft_strncmp("ss\n", str, 4)))
		{
			swap(final->a[0], final->a[1]);
			swap(final->b[final->a_size - final->curr_b_size], \
				final->b[final->a_size - final->curr_b_size + 1]);
		}
		else if (!(ft_strncmp("rr\n", str, 4)))
		{
			rot(final, 'a', final->a, final->curr_a_size);
			rot(final, 'b', final->b, final->curr_b_size);
		}
		else if (!(ft_strncmp("rrr\n", str, 4)))
		{
			rev_rot(final, 'a', final->a, final->curr_a_size);
			rev_rot(final, 'b', final->b, final->curr_b_size);
		}
		else
		{
			ft_printf("Error\n");
			free_stacks(final);
			free (str);
			exit(0);
		}	
		free(str);
		if (pipe)
			str = get_next_line(0);
		else
			str = get_next_line(1);
	}
	free (str);
	if (is_sorted(final))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(final);
}
