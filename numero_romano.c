int main(void)
{
    char    *number;
    char    *result;
    int    ret;
    scanf("Digite o numero romano: %s", number);
    ret = verify_valid_input(number);
    if (ret)
    {
        printf("Invalid input\n");
        return(1);
    }
    result = convert_int_to_rome(number);
    printf("%s\n", result);
    return(0);
}
