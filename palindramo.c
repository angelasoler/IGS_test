int main(void)
{
    int     pal_len;
    int     fd;
    char    *result;
    char    *aux;

    fd = open("arquivo.txt", O_RDONLY);
    while(read(fd, &letter, 1))
    {
        i++;
    }
    close(fd);
    result = malloc(sizeof(char) * i);
    fd = open("arquivo.txt", O_RDONLY);
    read(fd, result, i);
    close(fd);
    parsear_simbolos_e_espacos_e_pontoacoes(result);
    aux = inverter_string(result);
    pal_len = comparar_strings(result, aux);
    return(pal_len);
}