#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

static int	count_words(char const *s, char c)
{
	int	wc;

	s++;
	wc = 1;
	while (*s == c)
		s++;
	while (*s)
	{
		while (*s == c)
		{
			s++;
			if (*s != c && *s != '\0')
				wc++;
		}
		if (*s != '\0')
			s++;
	}
	return (wc);
}

static char	**result_array(char	**dest, char *s1, char c)
{
	char	*beg;
	int		i;

	i = 0;
	while (*s1)
	{
		beg = s1;
		while (*s1 != c && *s1 != '\0')
			s1++;
		if (*s1 != '\0')
		{
			*s1 = '\0';
			s1++;
		}
		dest[i] = strdup(beg);
		while (*s1 == c && *s1 != '\0')
			s1++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	**split(char const *s, char c)
{
	char	**result;
	char	*s1;
	int		size;
	int		i;

	i = 0;
	if (*s == 0)
	{
		result = malloc(sizeof(char *) * 1);
		result[0] = (char *)0;
		return (result);
	}
	s1 = strdup(s);
	size = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (0);
	while (s1[i] == c)
		i++;
	result = result_array(result, &s1[i], c);
	free(s1);
	return (result);
}

char	*reverse_s(char	*s, size_t len)
{
	char	*result;
	int		i;
	int		i2;

	i = 0;
	i2 = (int)len;
	result = malloc(sizeof(char) * (i2 + 1));
	while (i2 > 0)
	{
		result[i] = s[i2 - 1];
		i++;
		i2--;
	}
	result[i] = '\0';
	return (result);
}

int	verify_pal(char *s_reverse, char *s)
{
	int	i;

	i = 0;
	while (*s_reverse == *s && *s)
	{
		s_reverse++;
		s++;
		i++;
	}
	return (i);
}

int	find_palidrom(char *s)
{
	int		i;
	int		r;
	int		lenx;
	char	*s_reverse;
	char	*aux;

	i = 0;
	r = 0;
	lenx = 0;
	aux = NULL;
	s_reverse = reverse_s(s, strlen(s));
	while (s[i])
	{
		aux = strchr(s_reverse, s[i]);
		if (aux)
			r = verify_pal(&s[i], aux);
		if (lenx < r)
			lenx = r;
		i++;
	}
	free(s_reverse);
	return (lenx);
}

int main(void)
{
	int 	pal_len;
	int 	fd;
	int 	i;
	int 	x;
	char	letter;
	char	*result;
	char	**split_result;

	fd = open("arquivo.txt", O_RDONLY);
	pal_len = 0;
	i = 0;
	x = 0;
	while(read(fd, &letter, 1))
	{
		i++;
	}
	close(fd);
	result = malloc(sizeof(char) * i);
	fd = open("arquivo.txt", O_RDONLY);
	read(fd, result, i);
	close(fd);
	split_result = split(result, '\n');
	while (split_result[x])
	{
		pal_len = find_palidrom(split_result[x]);
		printf("O maoir palidromo em %s tem %d letras\n", split_result[x], pal_len);
		free(split_result[x]);
		x++;
	}
	free(result);
	free(split_result);
	return(0);
}
