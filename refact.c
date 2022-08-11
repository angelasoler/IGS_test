#include <stdio.h>
#include <stdlib.h>
#define LINHAS 3
#define COLUNAS 5

void	free_slot(int **slot);
void	init_int_vars(int *lines, int *cols, int *count_prize);

int **cria_slot(void)
{
	int **slot;
	int	col;
	int	line;

	line = 0;
	col = 0;
	slot = malloc (sizeof(int *) * LINHAS + 1);
	while (line < 3)
		slot[line++] = malloc (sizeof (int) * COLUNAS + 1);
	line = 0;
	while (line < 3)
	{
		printf("Insira os 5 valores da linha %d:\n", (line + 1));
		while (col < 5)
		{
			scanf("%d", &slot[line][col]);
			col++;
		}
		col = 0;
		line++;
	}
	return (slot);
}


int main (void)
{
	int	premio[LINHAS][COLUNAS] = {{1,0,0,0,1}, {0,1,0,1,0}, {0,0,1,0,0}};
	int	**slot;
	int	lines;
	int	cols;
	int	count_prize;

	slot = cria_slot();
	init_int_vars(&lines, &cols, &count_prize);
	while (lines < 3 && count_prize != 5)
	{
		while (cols < 5)
		{
			if (slot[lines][cols] == premio[lines][cols] && premio[lines][cols])
				count_prize++;
			cols++;
		}
		cols = 0;
		lines ++;
		if (lines == 3 && count_prize != 5)
		{
			printf("\n\n    ----Tente novamente!!----\n");
			free_slot(slot);
			init_int_vars(&lines, &cols, &count_prize);
			slot = cria_slot();
		}
	}
	free_slot(slot);
	printf ("Gahnou!\n");
	return (0);
}

void	free_slot(int **slot)
{
	int	lines;

	lines = 0;
	while (lines < 3)
		free (slot[lines++]);
	free(slot);
}

void	init_int_vars(int *lines, int *cols, int *count_prize)
{
	*lines = 0;
	*cols = 0;
	*count_prize = 0;
}
