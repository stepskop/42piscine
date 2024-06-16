#include <stdlib.h>
#include "structure.h"

char *read_br(char *s)
{
	char *b_str;
	int i;
	int j;

	i = 0;
	j = 0;
	b_str = malloc(16);
	while (s[i])
	{
		if (s[i] >= '1' && s[i] <= '4' && i < 32)
		{
			if (i < 24)
			{
				if ((s[i] + s[i + 8] - 96) < 3 || (s[i] + s[i + 8] - 96) > 5)
					return ("\0");
			}
			b_str[j] = s[i];
			j++;	
		}
		i++;
	}
	if (i >= 32)
		return("\0");
	return (b_str);
}

t_border fill_br(char *str)
{
	t_border b;
	int	i;

	i = 0;
	b.top = malloc(4);
	b.bottom = malloc(4);
	b.left = malloc(4);
	b.right = malloc(4);
	while (str[i])
	{
		if (i < 4)
			b.top[i] = str[i] - 48;
		else if (i < 8)
			b.bottom[i - 4] = str[i] - 48;
		else if (i < 12)
			b.left[i - 8] = str[i] - 48;
		else if (i < 16)
			b.right[i - 12] = str[i] - 48; 
		i++;
	}
	return (b);
}

void def_grid(t_cell c[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c[i][j].value = -1;
			c[i][j].x = i;
			c[i][j].y = j;
			j++;
		}
		i++;
	}
}