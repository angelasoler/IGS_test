struct ListaNode
{
	int		n;
	void	*next;
};

struct	ListaNode *mergeKListas(struct  ListNode **listas, int listasSize)
{

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
