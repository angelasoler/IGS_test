#include <stdio.h>

void calcu_steps(char *init, char *end,int steps)
{
    int size;

    if (end > init)
    {
        size = hex_to_int(end) - hex_to_int(init) / steps
        put_steps(size, init, end);
    }
    else if (init > end)
    {
        size = - 1 * (hex_to_int(init) - hex_to_int(end)) / steps
        put_steps_reverse(size, init, end);
    }
}

int main(void)
{
    char    *r_inicial;
    char    *r_final;
    int     steps;

    printf("cor inicial:");
    scanf("%s", r_inicial);
    printf("cor final:");
    scanf("%s", r_final);
    printf("steps:");
    scanf("%d", &steps);
    // calcu_steps(r_inicial, r_final, steps);
    printf("%s, %s, %d", r_inicial, r_final, steps);
    return(0);
}