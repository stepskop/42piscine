#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n >= 0)
	{
		write(1, "P", 1);
	}
	else if (n < 0 )
	{
		write(1, "N", 1);
	}
}

//Uncomment for testing
/*
int	main(void)
{
	ft_is_negative(3);
	ft_is_negative(-1);
	return (0);
}
*/