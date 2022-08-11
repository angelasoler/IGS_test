struct ListaNode
{
	int		n;
	void	*next;
};

struct	ListaNode *mergeKListas(struct  ListNode **listas, int listasSize)
{
	struct ListNode **aux;

	aux = listas;
	while (*aux[i])
	{
		aux[i] = listas[i]->next;
	}
}

int main(void)
{
	typedef struct ListaNode	listas;
	listas						**a;
	listas						*b;
	listas						*aux;
	int							i;

	i = 0;
	b = mergeKListas(a, 5);
	aux = b;
	while (aux)
	{
		printf("%d, ", b->n);
		aux = aux->next;
	}
	return(0);
}
