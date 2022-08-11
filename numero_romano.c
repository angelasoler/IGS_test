#include <stdio.h>
#include <string.h>

int digit(char c)
{
	int value;

	value = -1;
	switch(c)
	{
		case 'I': value = 1; break;
		case 'V': value = 5; break;
		case 'X': value = 10; break;
		case 'L': value = 50; break;
		case 'C': value = 100; break;
		case 'D': value = 500; break;
		case 'M': value = 1000; break;
		case '\0': value = 0; break;
	}
	return (value);
}

int main(void)
{
	char number[20];
	int	i;
	int n; 

	i = 0;
	n = 0;
	printf("Digite o numero romano: ");
	scanf("%s", number);
	while (number[i])
	{
		if (digit(number[i]) < 0)
		{
			printf("Input invalido\n");
			return (0);
		}
		if (digit(number[i]) >= digit(number[i + 1]))
			n = n + digit(number[i]);
		else
		{
			n = n + (digit(number[i + 1]) - digit(number[i]));
			i++;
		}
		i++;
	}
	printf("Resultado: %d\n", n);
	return (0);
}
