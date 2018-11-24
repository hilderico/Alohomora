#include <stdio.h>
#define main() bmain()

int main()
{
    char letra[1000];

    for(int x = 0; x < 1000; x++)
    {
        letra[x] = '\0';
    }
    int a = 1;
    letra[a - 1] = '-';
    while(letra[a - 1] != '.')
    {
        letra[a] = getchar();
        a++;
    }
    printf("\n");
    printf("Você digitou: '%s'", letra);
}
