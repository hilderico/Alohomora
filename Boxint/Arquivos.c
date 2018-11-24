#include <stdio.h>

//global variables
FILE *Arquivo;
char recebe[200][200];

//functions
void escreve(char lescreve[200]){
    Arquivo = fopen("Texto.txt","a");
    fprintf(Arquivo, "%s",lescreve);
    fclose (Arquivo);
}

char envia(char env[200]){
    int x = 0;
    char lrecebe[200];
    while (env[x] != '\0'){
        lrecebe[x] = env[x];
        x++;
    }
    return lrecebe;
}

void lendo(){
    Arquivo = fopen("Texto.txt","r");
	//zerando global recebe[][]
    for(int y = 0; y < 200; y++)
    {
        for(int x = 0; x < 200; x++){
            recebe[y][x] = '\0';
        }
    }
    int x = 0;
    while (!feof(Arquivo))
    {
        fgets(recebe[x], 100, Arquivo);  // o 'fgets' lê até 99 caracteres ou até o '\n'
        printf("recebe = %s",recebe[x]);
        x++;
    }
    fclose (Arquivo);
}

void resetarq(){
    Arquivo = fopen("Texto.txt","w");
    fclose (Arquivo);
}

void limpa(char lescreve[],int ltam){

    for(int x = 0; x < ltam;x++)
    {
        lescreve[x] = '\0';
    }

}

void seeking(char seek[],char bloc[200][200]){


    int x = 0;
    int y = 0;
    int z = 0;

 //   printf("antes de entrar no while...\n");
 //   printf("y = %d\n",y);
 //   printf("seek = %s\n",seek);
 //   printf("seek[y] = %c\n",seek[y]);
 //   printf("seek[0] = %c\n",seek[0]);
 //   printf("seek[1] = %c\n",seek[1]);
 //   printf("seek[2] = %c\n",seek[2]);
 //   printf("bloc[0][z] = %d\n",bloc[z][0]);
 //   printf("bloc[1][z] = %d\n",bloc[z][1]);
 //   printf("bloc[2][z] = %d\n",bloc[z][2]);
    while((seek[y] != '\0') && (bloc[z][0] != '\0')){
 //       printf("y = %d\n",y);
 //       printf("seek[y] = %c\n",seek[y]);
 //       printf("x = %d\n",x);
 //       printf("z = %d\n",z);
 //       printf("bloc[z][x] = %c\n",bloc[z][x]);

        if(seek[y] == bloc[z][x + y]){
 //          printf("SIM === seek[y](%d)(%c) = bloc[z][x + y](%d)(%d+%d) (%c)=====\n",
 //                  y,seek[y],z,x,y,bloc[z][x + y]);
            y++;
        }
        else
        {
 //           printf("NAO === seek[y](%d)(%c) = bloc[z][x + y](%d)(%d+%d) (%c)=====\n",
 //                  y,seek[y],z,x,y,bloc[z][x + y]);
            y = 0;
            x++;
        }
        if(bloc[z][x] == '\0'){
            x = 0;
            z++;
        }
 //       printf("=======\n=====\n");
 //       getchar();
    }

    if(seek[y] == '\0'){
        printf("palavra encontrada ... fim");
    }
    else
    {
        printf("NAO ENCONTRADA ... fim");
    }

}

int dseeking(char seek[],char bloc[200][200]){


    int x = 0;
    int y = 0;
    int z = 0;


    printf("antes de entrar no while...\n");
    printf("y = %d\n",y);
    printf("seek = %s\n",seek);
    printf("seek[y] = %c\n",seek[y]);
    printf("seek[0] = %c\n",seek[0]);
    printf("seek[1] = %c\n",seek[1]);
    printf("seek[2] = %c\n",seek[2]);
    printf("bloc[z][0] = %d\n",bloc[z][0]);
    printf("bloc[z][1] = %d\n",bloc[z][1]);
    printf("bloc[z][2] = %d\n",bloc[z][2]);
    while((seek[y] != '\0') && (bloc[z][0] != '\0')){
        printf("y = %d\n",y);
        printf("seek[y] = %c\n",seek[y]);
        printf("x = %d\n",x);
        printf("z = %d\n",z);
        printf("bloc[z][x] = %c\n",bloc[z][x]);

        if(seek[y] == bloc[z][x + y]){
           printf("SIM === seek[y](%d)(%c) = bloc[z][x + y](%d)(%d+%d) (%c)=====\n",
                   y,seek[y],z,x,y,bloc[z][x + y]);
            y++;
        }
        else
        {
            printf("NAO === seek[y](%d)(%c) = bloc[z][x + y](%d)(%d+%d) (%c)=====\n",
                   y,seek[y],z,x,y,bloc[z][x + y]);
            y = 0;
            x++;
        }
        if(bloc[z][x] == '\0'){
            x = 0;
            z++;
        }
        printf("=======\n=====\n");
        getchar();
    }

    if(seek[y] == '\0'){
        printf("palavra encontrada ... fim");
        return 0;
    }
    else
    {
        printf("NAO ENCONTRADA ... fim\n");
        printf("FINALIZANDO...\n");
        printf("y = %d\n",y);
        printf("seek[y] = %c\n",seek[y]);
        printf("x = %d\n",x);
        printf("z = %d\n",z);
        printf("bloc[z][x] = %c\n",bloc[z][x]);
        printf("bloc[z][x] = %d\n",bloc[z][x]);

        for(int x = 0; x < 3; x++){
            printf("{");
            for(int y = 0; y < 20; y++){
                printf("%d,",bloc[x][y]);
            }
            printf("}");
        }

    }
    return 2;
}

char lendoeprocurando(char lescreve[]){
    Arquivo = fopen("Texto.txt","r");
    char lrecebe[200][200];
    for(int y = 0; y < 200; y++)
    {
        for(int x = 0; x < 200; x++){
            lrecebe[x][y] = '\0';
        }
    }
    int retsk = 1;
    int x = 0;
    while ((!feof(Arquivo)) && (retsk != 0))
    {
        fgets(lrecebe[x], 200, Arquivo);  // o 'fgets' lê até 99 caracteres ou até o '\n'
        printf("lrecebe = %s",lrecebe[x]);
        retsk = dseeking(lescreve,lrecebe[x]);
        x++;
    }
    // TODO
    /*
        Continuar a ler de onde a palavra foi encontrada

    */




    fclose (Arquivo);
    return lrecebe;
}

int menu(){
    int opc = 0;
    while(opc != 9)
    {
        printf("=== MENU ===\n");
        printf("1. Escrever\n");
        printf("2. Ler\n");
        printf("3. Resetar\n");
        printf("4. Localizar\n");
        printf("5. Localizar nos Arquivos\n");
        printf("9. Saida\n");
        printf(">");
        scanf("%d",&opc);
        switch(opc)
        {
            case 1:
            {
                printf("\n>");
                char lescreve[200];
                limpa(lescreve,200);
                int a = 1;
                lescreve[a - 1] = '-';
                while(lescreve[a - 1] != '.')
                {
                    lescreve[a] = getchar();
                    a++;
                }
                lescreve[a - 1] = '\0';

                a = 0;
                /*
                while(lescreve[a] != '\0'){
                    printf("%c",lescreve[a]);
                    a++;
                }
                */
                escreve(lescreve);
                printf("\n");
                break;
            }
            case 2:
            {
                printf("\n>");
                lendo();
                printf("\n");
                break;
            }
            case 3:
            {
                printf("\n>");
                resetarq();
                printf("\n");
                break;
            }
            case 4:
            {
                printf("Escreva a palavra que deseja pesquisar\n");
                printf("\n>");
                char lescreve[200];
                limpa(lescreve,200);
                int a = 1;
                lescreve[a - 1] = '-';
                while(lescreve[a - 1] != '.')
                {
                    lescreve[a] = getchar();
                    a++;
                }
                lescreve[a - 1] = '\0';
                a = 1;
                while(a < 200)
                {
                    lescreve[a - 1] = lescreve[a];
                    a++;
                }
                a = 1;
                while(a < 200)
                {
                    lescreve[a - 1] = lescreve[a];
                    a++;
                }
                seeking(lescreve,recebe);
                printf("\n");
                break;
            }
            case 5:
            {
                printf("Escreva a palavra que deseja pesquisar\n");
                printf("\n>");
                char lescreve[200];
                limpa(lescreve,200);
                int a = 1;
                lescreve[a - 1] = '-';
                while(lescreve[a - 1] != '.')
                {
                    lescreve[a] = getchar();
                    a++;
                }
                lescreve[a - 1] = '\0';
                a = 1;
                while(a < 200)
                {
                    lescreve[a - 1] = lescreve[a];
                    a++;
                }
                a = 1;
                while(a < 200)
                {
                    lescreve[a - 1] = lescreve[a];
                    a++;
                }
                lendoeprocurando(lescreve);
                printf("\n");
                break;
            }
            case 9:
            {
                printf("Tchau\n");
                break;
            }
        }
    }
    //lendo();
    return 0;
}
