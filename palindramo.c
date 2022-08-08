int main(void)
{
    int     pal_len;
    int     fd;
    char    *result;
    char    **split_result;
    char    *aux;

    fd = open("arquivo.txt", O_RDONLY);
    pal_len = 0;
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
    aux = split(result, '\n');
    while (split_result[i])
    {
        aux[i] = inverter_string(split_result[i]);
        if (pal_len < comparar_strings(result[i], aux[i]);)
            pal_len = comparar_strings(result[i], aux[i]);
    }
    return(pal_len);
}