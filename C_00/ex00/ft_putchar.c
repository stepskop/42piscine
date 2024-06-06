#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// Uncomment to test
/*
int	main(void)
{
	ft_putchar('a');
	return (0);
}
*/
