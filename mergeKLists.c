#include<stdio.h> 
#include<stdlib.h> 

struct ListNode
{
	int				n;
	struct ListNode	*next;
};

void	freeList(struct ListNode *head);
void	insertAtTheBegin(struct ListNode **start_ref, int n);
void	bubbleSort(struct ListNode *start);
void	swap(struct ListNode *a, struct ListNode *b);
void	printList(struct ListNode *start);

struct	ListNode *mergeKListas(struct ListNode **listas, int listasSize)
{
	struct ListNode	*aux;
	struct ListNode	*result;
	int		i;

	i = 0;
	result = NULL;
	while (i < listasSize)
	{
		aux = listas[i];
		while (aux)
		{
			insertAtTheBegin(&result, aux->n);
			aux = aux->next;
		}
		freeList(listas[i]);
		i++;
	}
	freeList(listas[i]);
	free(listas);
	bubbleSort(result);
	return (result);
}

void	bubbleSort(struct ListNode *start) 
{ 
	int		swapped;
	struct	ListNode *ptr1;
	struct	ListNode *lptr;

	if (start == NULL) 
		return ;
	swapped = 1;
	lptr = NULL;
	while (swapped)
	{
		swapped = 0;
		ptr1 = start;
		while (ptr1->next != lptr)
		{ 
			if (ptr1->n > ptr1->next->n)
			{ 
				swap(ptr1, ptr1->next);
				swapped = 1;
			} 
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} 
}

int	main(void)
{
	int	list0[] = {1, 3, 8};
	int	list1[] = {1, 3, 6};
	int	list2[] = {8, 9};
	struct ListNode	**listas; 
	struct ListNode	*result;
	int	i;

	listas = calloc(sizeof(struct ListNode *), 4);
	 for (i = 0; i< 3; i++) 
		insertAtTheBegin(&listas[0], list0[i]);
	 for (i = 0; i< 3; i++) 
		insertAtTheBegin(&listas[1], list1[i]);
	 for (i = 0; i< 2; i++) 
		insertAtTheBegin(&listas[2], list2[i]);
	result = mergeKListas(listas, 3);
	printf("output: ");
	printList(result);
	freeList(result);
}

void	insertAtTheBegin(struct ListNode **start_ref, int n) 
{ 
	struct ListNode	*ptr1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	ptr1->n = n;
	ptr1->next = *start_ref;
	*start_ref = ptr1;
} 

void	printList(struct ListNode *start) 
{ 
	struct ListNode	*temp = start;

	while (temp)
	{
		printf("%d ", temp->n);
		temp = temp->next;
	}
	printf("\n");
}


void	swap(struct ListNode *a, struct ListNode *b) 
{
	int temp = a->n;
	a->n = b->n;
	b->n = temp;
} 

void freeList(struct ListNode *head)
{
	struct ListNode *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
