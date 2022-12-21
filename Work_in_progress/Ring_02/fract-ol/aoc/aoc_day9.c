#include <stdio.h>
#include "libft/incs/libft.h"
#include <math.h>

typedef struct s_point_aoc
{
	int	x;
	int	y;
}	t_point_aoc;

typedef struct s_list_aoc
{
	int	x;
	int	y;
	struct s_list_aoc	*next;
}	t_list_aoc;

int	get_number_lines(char *str, int fd)
{
	int	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;

	}
	free(str);
	close(fd);
	return (i);
}

char	**copy_to_arr(char *str, int fd, char **arr, char **argv)
{
	int	i = 0;
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		//arr[i] = ft_calloc(ft_strlen(str) + 1, sizeof(char));
		arr[i] = ft_strdup(str);
		//printf("%s", arr[i]);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	return (arr);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	fd = open(argv[1], O_RDONLY);
		char **arr;
		int	i;
		char *str = NULL;
		i = get_number_lines(str, fd);
		arr = ft_calloc(i + 1, sizeof(char *));
		arr = copy_to_arr(str, fd, arr, argv);
		i = 0;
		while (arr[i])
		{
			//printf("%s", arr[i]);
			i++;
		}
		free(str);
		close(fd);
		printf("\n\n");
		i = 0;
		t_list_aoc	*positions;
		positions = (t_list_aoc *)malloc(sizeof(t_list_aoc));
		t_point_aoc	h;
		t_point_aoc	t;
		int	distance = 0;
		h.x = 1;
		h.y = 1;
		t.x = 1;
		t.y = 1;
		positions->x = t.x;
		positions->y = t.y;
		positions->next = NULL;
		t_list_aoc	*begin = positions;

		printf("%d.%d\n", h.y, h.x);
		printf("%d.%d\n\n", begin->y, begin->x);				
		while (arr[i])
		{
			printf("%s", arr[i]);
			if (arr[i][0] == 'R')
			{
				arr[i]++;
				distance = ft_atoi(arr[i]);
				while (distance)
				{
					h.x++;
					distance--;
					if (abs(t.x - h.x) > 1)
					{
						t.x++;
						if (abs(t.y - h.y) >= 1)
						{
							if (t.y < h.y)
								t.y++;
							else
								t.y--;
						}
						positions->next = malloc(sizeof(t_list_aoc));
						positions->next->x = t.x;
						positions->next->y = t.y;
						positions = positions->next;
					}
				}
				printf("%d.%d\n", h.y, h.x);
			}
			else if (arr[i][0] == 'L')
			{
				arr[i]++;
				distance = ft_atoi(arr[i]);
				while (distance)
				{
					h.x--;
					distance--;
					if (abs(t.x - h.x) > 1)
					{
						t.x--;
						if (abs(t.y - h.y) >= 1)
						{
							if (t.y < h.y)
								t.y++;
							else
								t.y--;
						}
						positions->next = malloc(sizeof(t_list_aoc));
						positions->next->x = t.x;
						positions->next->y = t.y;
						positions = positions->next;
					}
				}
				printf("%d.%d\n", h.y, h.x);
			}
			else if (arr[i][0] == 'U')
			{
				arr[i]++;
				distance = ft_atoi(arr[i]);
				while (distance)
				{
					h.y++;
					distance--;
					if (abs(t.y - h.y) > 1)
					{
						t.y++;
						if (abs(t.x - h.x) >= 1)
						{
							if (t.x < h.x)
								t.x++;
							else
								t.x--;
						}
						positions->next = malloc(sizeof(t_list_aoc));
						positions->next->x = t.x;
						positions->next->y = t.y;
						positions = positions->next;
					}
					//printf("\n%d.%d\n", h.y, h.x);
					//printf("%d.%d\n", t.y, t.x);
				}
				printf("%d.%d\n", h.y, h.x);
			}
			else if (arr[i][0] == 'D')
			{
				arr[i]++;
				distance = ft_atoi(arr[i]);
				while (distance)
				{
					h.y--;
					distance--;
					if (abs(t.y - h.y) > 1)
					{
						t.y--;
						if (abs(t.x - h.x) >= 1)
						{
							if (t.x < h.x)
								t.x++;
							else
								t.x--;
						}
						positions->next = malloc(sizeof(t_list_aoc));
						positions->next->x = t.x;
						positions->next->y = t.y;
						positions = positions->next;
					}
				}
				printf("%d.%d\n", h.y, h.x);
			}
			printf("%d.%d\n\n", t.y, t.x);			
			i++;
		}
		positions->next = 0;
		int	same = 0;
		i = 0;
		t_list_aoc	*temp = begin->next;
		while(begin)
		{
			i++;
			while (temp)
			{
				//printf("%d %d, %d %d\n", begin->y, begin->x, temp->y,  temp->x);
				if (begin->x == temp->x && begin->y == temp->y)
				{
					same++;
					break ;
				}
				temp = temp->next;
			}
			//printf("%d.%d\n", begin->y, begin->x);
			begin = begin->next;
			if (begin && begin->next)
				temp = begin->next;
		}
		printf("i is %d, same is %d\n", i, same);
		printf("unique places is %d\n", i - same);
	}


}