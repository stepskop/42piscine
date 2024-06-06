#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	ch;

	ch = 'z';
	while (ch >= 'a')
	{
		write(1, &ch, 1);
		ch--;
	}
}

//Uncomment for test
/*
int	main(void)
{
	ft_print_reverse_alphabet();
}
*/
