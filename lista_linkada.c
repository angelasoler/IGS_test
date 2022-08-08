typedef struct s_list
{
    int         *list;
    list_node    *next;
} list_node;

int main(void)
{
    char    *s;
    char    *result;
    list_node **list;

    scanf("input: %s",s);
    list = alloc_list(s);
    result = merge_list(list);
    printf("[%s]", result)
    return(0);
}
