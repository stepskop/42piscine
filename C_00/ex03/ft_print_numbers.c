#include <unistd.h>

void	ft_print_numbers(void)
{
	char	num;

	num = '0';
	while (num <= '9')
	{
		write(1, &num, 1);
		num++;
	}
}

//Uncomment for test
/*
int	main(){
	ft_print_numbers();
	return (0);
}
*/