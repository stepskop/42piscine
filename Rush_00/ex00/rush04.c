/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <sskopek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:03:05 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/08 18:30:49 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	top_line(int width)
{
	// Print top line "ABBBC" using 'ft_putchar' function
	int count = 0;

	while (count < width)
	{
		if (count == 0) // print 'A' at the start of the width counting.
		{
			ft_putchar('A');
		}
		else if (count == width - 1) // print 'C' at the end of the width counting.
		{
			ft_putchar('C');
		}
		else // print 'B' in every space in the middle of the width counting.
		{
			ft_putchar('B');
		}
		count++;
	}
	ft_putchar('\n');
}

void	mid_line(int width)
{
	// Print mid line "B   B" using 'ft_putchar' function
	int	i;
	
	if (width == 1)		// if width is only 1, print one B 
	{
		ft_putchar('B');
	} 
	else if (width >= 2) // if width is 2 or more, print BB with (widht - 2)times 'space' between them
	{
		ft_putchar('B');
		i = 0;
		while (width - 2 > i)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar('B');
	}
	ft_putchar('\n');
}

void	bottom_line(int width)
{
	// Print bottom line "CBBBA" using 'ft_putchar' function
}

void	rush(int width, int height)
{
	// Logic of calling these function based on height
	int count = 0;

	while (count < height)
	{
		if (count == 0) // print the first line of the height counting.
		{
			top_line(width);
		}
		else if (count == height - 1) // print the last line of the height counting.
		{
			bottom_line(width);
		}
		else // print the rest of the lines in the middle of the height counting.
		{
			mid_line(width);
		}
		count++;
	}
}