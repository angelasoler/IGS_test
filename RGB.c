
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void			put_steps_reverse(unsigned int size, unsigned int init, int steps);
void			put_steps(unsigned int size, unsigned int init, int steps);
void			reverse_write_digits(char *s, int count);
unsigned int	hex_to_int(char *n_hex);

void	calcu_steps(char *init, char *end, int steps)
{
	unsigned int	size;
	unsigned int	n_init;
	unsigned int	n_end;

	n_init = hex_to_int(init);
	n_end = hex_to_int(end);
	if (n_end > n_init)
	{
		size = (n_end - n_init) / steps;
		put_steps(size, n_init, steps);
	}
	else if (n_init > n_end)
	{
		size = (n_init - n_end) / steps;
		put_steps_reverse(size, n_init, steps);
	}
}

int	main(void)
{
	char	r_inicial[20];
	char	r_final[20];
	int		steps;

	printf("cor inicial: ");
	scanf("%s", r_inicial);
	printf("cor final: ");
	scanf("%s", r_final);
	printf("steps: ");
	scanf("%d", &steps);
	if (steps < 0)
	{
		printf("Invalid input\n");
		return (0);
	}
	calcu_steps(r_inicial, r_final, steps);
	return(0);
}

void	reverse_write_digits(char *s, int count)
{
	while (count)
	{
		count--;
		write(1, &s[count], 1);
	}
	write(1, "\n", 1);
}

unsigned int	hex_to_int(char *n_hex)
{
	int				i;
	int				base;
	unsigned int	result;

	i = strlen(n_hex) - 1;
	base = 1;
	result = 0;
	while (i >= 0)
	{
		if(n_hex[i] >= '0' && n_hex[i] <= '9')
			result += (n_hex[i] - 48) * base;
		else if(n_hex[i] >= 'A' && n_hex[i] <= 'F')
			result += (n_hex[i] - 55) * base;
		base *= 16;
		i--;
	}
	return (result);
}

void	put_hexa(unsigned int n)
{
	char	temp[9];
	int		i;

	i = 0;
	while (n)
	{
		if (n % 16 > 9)
			temp[i] = (n % 16) + 55;
		else
			temp[i] = (n % 16) + 48;
		n /= 16;
		i++;
	}
	temp[i] = '\0';
	reverse_write_digits(temp, i);
}

void	put_steps(unsigned int size, unsigned int init, int steps)
{
	while (steps > 0)
	{
		init += size;
		put_hexa(init);
		steps--;
	}
}

void	put_steps_reverse(unsigned int size, unsigned int init, int steps)
{
	while (steps > 0)
	{
		init = init - size;
		put_hexa(init);
		steps--;
	}
}
