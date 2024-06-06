#include <unistd.h>

void	ft_printnum(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (!(c == '9' && b == '8' && a == '7'))
		write(1, ", ", 1);
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = '0';
	b = '0';
	c = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				ft_printnum(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}

// Uncomment for testing
/*
int main(void)
{
	ft_print_comb();
	return (0);
}
*/
