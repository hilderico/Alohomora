#include <stdio.h>
#define main() amain()
int main(){
    char bloc[] = {"asdfsafasfdefaultfgsdgdsgs"};
    char seek[] = "default";
    int x = 0;
    int y = 0;


    while((seek[y] != '\0') && (bloc[x] != '\0')){
        printf("y = %d\n",y);
        printf("seek[y] = %c\n",seek[y]);
        printf("x = %d\n",x);
        printf("bloc[x] = %c\n",bloc[x]);

        if(seek[y] == bloc[x+y]){
           // printf("SIM === seek[y](%d)(%c) = bloc[x+y](%d+%d)(%c)=====\n",
           //        y,seek[y],x,y,bloc[x+y]);
            y++;
        }
        else
        {
            //printf("NAO === seek[y](%d)(%c) = bloc[x+y](%d+%d)(%c)=====\n",
            //       y,seek[y],x,y,bloc[x+y]);
            y = 0;
            x++;
        }
        printf("=======\n=====\n");
        //getchar();
    }

    if(seek[y] == '\0'){
        printf("palavra encontrada ... fim");
    }
    else
    {
        printf("NAO ENCONTRADA ... fim");
    }
    /* EXEMPLO */
    /*
    seek[x+y] == bloc[x+y]
    if true
        y++;
    if false
        y = 0;
        x++;
    seek[x+0] = bloc[x+0] N
    seek[x+0] = bloc[x+0] Y
    seek[x+1] = bloc[x+1] N
    seek[x+0] = bloc[x+0] N
    ...

    seek[x+5] = bloc[x+5] Y

    printf("palavra localizada ... fim");
    */

    return 0;
}
