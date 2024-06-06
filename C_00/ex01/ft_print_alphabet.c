#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	ch;

	ch = 'a';
	while (ch <= 'z')
	{
		write(1, &ch, 1);
		ch++;
	}
}

//Uncomment to test
/*
void	main(void)
{
	ft_print_alphabet();
}
*/
