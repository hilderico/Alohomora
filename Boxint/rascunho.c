

lendoeprocurando("@x");

struct LrecebeResultsk LrecebeResult;
LrecebeResult = LendoeProcurandoParam("@x", ";");

ler while seek != ".,";
pos = ftell(arquivo);
seek "@y";
pos = ftell(arquivo);
ler while seek != ".,";



struct LrecebeResultsk{
    char lrecebe[200][200];
    char resultsk[200];
};




struct LrecebeResultsk LendoeProcurandoParam(char lescreve[], char param1){
    Arquivo = fopen("Texto.txt","r");
    struct LrecebeResultsk stcvar;

    for(int y = 0; y < 200; y++)
    {
        for(int x = 0; x < 200; x++){
            lrecebe[x][y] = '\0';
            stcvar.lrecebe[x][y]
        }
    }
    int retsk = 1;
    int x = 0;
    while ((!feof(Arquivo)) && (retsk != 0))
    {
        fgets(stcvar.lrecebe[x], 200, Arquivo);  // o 'fgets' lê até 99 caracteres ou até o '\n'
        printf("stcvar.lrecebe = %s",stcvar.lrecebe[x]);
        retsk = dseeking(lescreve,stcvar.lrecebe[x]);
        if (retsk == 0){
            int y = 0;
            while(stcvar.lrecebe[x][y - 1] != ';'){
                resultsk[y] = lrecebe[x][y];
                stcvar.resultsk[y] = stcvar.lrecebe[x][y];
                //printf("areatypevar.name[%d][%d] = %c\n",listx,listy,listname[listx][listy]);
                y++;
            }
            stcvar.resultsk[y - 1] = '\0';
        }
        x++;
    }
    fclose (Arquivo);
    return stcvar;
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
