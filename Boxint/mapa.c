#include <stdio.h>

int x = 25;
int y = 30;

int areainix[100];
int areainiy[100];
int areafimx[100];
int areafimy[100];

char listname[100][50] = {
    "Area 1",
    "Area 2",
    "Area 3",
    "Area 4",
    "Area 5",
    "Area 6",
    "Area 7",
    "Area 8",
    "Area 9",
    "Area 10",
    "Area 11",
    "Area 12",
    "Area 13",
    "Area 14",
    "Area 15",
    "Area 16",
    "Area 17",
    "Area 18",
    "Area 19",
    "Area 20",
    "Area 21",
    "Area 22",
    "Area 23",
    "Area 24"
};

struct Areatype{
    char name[100][50];
    int idx;
};

struct Areatype areafunc(char listname[100][50]);
struct Areatype arealocalizefunc();
struct Areatype copia(struct Areatype areatypevar,char listname[100][50]);
struct Areatype debugcopia(struct Areatype areatypevar,char listname[100][50]);
struct Areatype areafunc(char listname[100][50]);
void informacao();
void controle();
void marcalocal();
void debugmarcalocal();
void debugarea();

int main(){

    marcalocal();
    printf("Minha posicao: x = %d, y = %d\n",x,y);
    int opc = 0;

    while (opc != 9){
        printf("escolha uma das opcoes:\n");
        printf("    1. Andar\n");
        printf("    2. informacao\n");
        printf("    9. Sair\n");
        printf(">");
        scanf("%d",&opc);

        if (opc == 1){
        controle();
        }
        else
        if (opc == 2){
        informacao();
        }
        else
        {
            printf("Opcao Invalida !!!\n");
        }

    }

    printf("Ate a proxima!!!");


    return 0;
}

struct Areatype arealocalizefunc(){
    struct Areatype areanewfunc = areafunc(listname);
    areanewfunc.idx = 0;
    while(areanewfunc.idx < 100){
        if((x > areainix[areanewfunc.idx]) && (x < areafimx[areanewfunc.idx]) && (y > areainiy[areanewfunc.idx]) && (y < areafimy[areanewfunc.idx])){
            //printf("Voce Esta Dentro de ...\n %s \n",areanewfunc.name[areanewfunc.idx]);
            break;
        }
        areanewfunc.idx++;
    }
    return areanewfunc;

}

void informacao(){
struct Areatype areatypevar;

printf("==== LOCALIZACAO ATUAL ===\n");
printf("(%d,%d)\n",x,y);
areatypevar = arealocalizefunc();
printf("area atual = %s\n\n",areatypevar.name[areatypevar.idx]);
}

struct Areatype copia(struct Areatype areatypevar,char listname[100][50]){
    int listx = 0;
    int listy = 0;
    //printf("Dentro de void copia..\n");
    //printf("Dentro de while(listname[listx][0] != \'\\0\')..\n");
    while(listname[listx][0] != '\0'){

        //printf("Dentro de while(listy < 50)..\n");
        while(listy < 50){

            areatypevar.name[listx][listy] = listname[listx][listy];
            //printf("areatypevar.name[%d][%d] = %c\n",listx,listy,listname[listx][listy]);
            listy++;
        }
        //printf("areatypevar.name[%d] = %s\n",listx,areatypevar.name[listx]);
        listx++;
        listy = 0;
    }
    return areatypevar;
}

struct Areatype debugcopia(struct Areatype areatypevar,char listname[100][50]){
    int listx = 0;
    int listy = 0;
    printf("Dentro de void copia..\n");
    printf("Dentro de while(listname[listx][0] != \'\\0\')..\n");
    while(listname[listx][0] != '\0'){

        printf("Dentro de while(listy < 50)..\n");
        while(listy < 50){

            areatypevar.name[listx][listy] = listname[listx][listy];
            printf("areatypevar.name[%d][%d] = %c\n",listx,listy,listname[listx][listy]);
            listy++;
        }
        printf("areatypevar.name[%d] = %s\n",listx,areatypevar.name[listx]);
        listx++;
        listy = 0;
    }
    return areatypevar;
}

struct Areatype areafunc(char listname[100][50]){
    struct Areatype lareavar;
    lareavar = copia(lareavar,listname);
    return lareavar;
}

void controle(){
    int andx = 0;
    int andy = 0;
    char key = '\0';
    int intkey = (int) key;

    while(key != 'p'){
        intkey = (int) key;
        if(intkey != 10){
            printf("Digite uma das seguintes opcoes: ...\n");
            printf("d -> para direita\n");
            printf("a -> para esquerda\n");
            printf("w -> para cima\n");
            printf("s -> para baixo\n");
            printf("p -> para SAIR\n");
            printf(">");
        }
        scanf("%c",&key);
        //printf("key = %d\n",key);
        //key = getchar();
        if(key == 'd'){
            // andar pro leste
            andx = 1;
            printf("Andando pro Leste ...\n");
            x += andx;
            printf("Minha posicao: x = %d, y = %d\n",x,y);
        }

        if(key == 'a'){
        // andar pro Oeste
            andx = -1;
            printf("Andando pro Oeste ...\n");
            x += andx;
            printf("Minha posicao: x = %d, y = %d\n",x,y);
        }
        if(key == 'w'){
            // andar pro Norte
            andy = 1;
            printf("Andando pro Norte ...\n");
            y += andy;
            printf("Minha posicao: x = %d, y = %d\n",x,y);
        }
        if(key == 's'){
            // andar pro Sul
            andy = -1;
            printf("Andando pro Sul ...\n");
            y += andy;
            printf("Minha posicao: x = %d, y = %d\n",x,y);
        }
    }


    /*
    // Correndo pro leste
    andx = 2;
    printf("Correndo pro Leste ...\n");
    x += andx;
    printf("Minha posicao: x = %d, y = %d\n",x,y);
    // Correndo pro Oeste
    andx = -2;
    printf("Correndo pro Oeste ...\n");
    x += andx;
    printf("Minha posicao: x = %d, y = %d\n",x,y);
    // Correndo pro Norte
    andy = 2;
    printf("Correndo pro Norte ...\n");
    y += andy;
    printf("Minha posicao: x = %d, y = %d\n",x,y);
    // Correndo pro Sul
    andy = -2;
    printf("Correndo pro Sul ...\n");
    y += andy;
    printf("Minha posicao: x = %d, y = %d\n",x,y);
    */

}

void marcalocal(){
    int conta = 0;
    //printf("Entrando dentro de ... while(areainix[conta - 1] != 100)...\n");
    while((areainix[conta - 1] != 100) && (conta != 100)){
        //printf("conta = %d\n",conta);
        if(conta == 0){
            areainix[conta] = 0;
            areainiy[conta] = 0;
            areafimx[conta] = 20;
            areafimy[conta] = 20;
        }
        else
        {
            if(areafimy[conta - 1] == 120){
                areafimy[conta - 1] = 20;
                areafimx[conta - 1] = areafimx[conta - 1] + 20;
                areainix[conta] = areainix[conta - 1] + 20;
            }
            areainix[conta] = areainix[conta - 1];
            areainiy[conta] = areafimy[conta - 1];
            areafimx[conta] = areafimx[conta - 1];
            areafimy[conta] = areafimy[conta - 1] + 20;

            if(areainiy[conta] == 100){
                    areainiy[conta] = 0;
                    areainix[conta] += 20;
            }
        }
        conta++;
    }
    //printf("SAIDA ... while(areainix[conta - 1] != 100)...\n");
}

void debugmarcalocal(){
    int conta = 0;
    printf("Entrando dentro de ... while(areainix[conta - 1] != 100)...\n");
    while((areainix[conta - 1] != 100) && (conta != 100)){
        printf("conta = %d\n",conta);
        if(conta == 0){
            areainix[conta] = 0;
            areainiy[conta] = 0;
            areafimx[conta] = 20;
            areafimy[conta] = 20;
        }
        else
        {
            if(areafimy[conta - 1] == 120){
                areafimy[conta - 1] = 20;
                areafimx[conta - 1] = areafimx[conta - 1] + 20;
                areainix[conta] = areainix[conta - 1] + 20;
            }
            areainix[conta] = areainix[conta - 1];
            areainiy[conta] = areafimy[conta - 1];
            areafimx[conta] = areafimx[conta - 1];
            areafimy[conta] = areafimy[conta - 1] + 20;

            if(areainiy[conta] == 100){
                    areainiy[conta] = 0;
                    areainix[conta] += 20;
            }
        }
        conta++;
    }
    printf("SAIDA ... while(areainix[conta - 1] != 100)...\n");
}

void debugarea(){
    printf("======= AREA =======\n");
    for(int fx = 0; fx < 100; fx++){
        printf("areainix[%d] = %d\n",fx,areainix[fx]);
        printf("areainiy[%d] = %d\n",fx,areainiy[fx]);
        printf("areafimx[%d] = %d\n",fx,areafimx[fx]);
        printf("areafimy[%d] = %d\n",fx,areafimy[fx]);
        printf("+--------------------+\n");
    }
    printf("======= fim da AREA =======\n");
}

