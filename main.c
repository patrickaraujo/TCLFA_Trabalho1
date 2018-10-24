#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int scanner1(char *x){
    int i = 0;
    char c;

    q0: c = x[i];
    if(c == 'a'){
        i++;
        goto q1;
    }
    else
        return scanner2(x);
    q1: c = x[i];
    if(c == 'a' || c == 'b'){
        i++;
        goto q2;
    }
    else
        return scanner2(x);
    q2: c = x[i];
    if( (c == 'a') && (x[i+1] != 'a' && x[i+1] != 'b') )
        return 1;
    else
        return scanner2(x);
    return 0;
}

int scanner2(char *x){
    int i = 0;
    char c;

    q0: c = x[i];
    if(c == 'a' || c == 'b'){
        i++;
        goto q1;
    }
    else
        return 0;
    q1: c = x[i];
    if(c == 'a'){
        i++;
        goto q2;
    }
    else
        return scanner3(x);
    q2: c = x[i];
    if(c == 'a'){
        i++;
        goto q3;
    }
    else
        return scanner3(x);
    q3: c = x[i];
    if( (c == 'a' || c == 'b') && (x[i+1] != 'a' && x[i+1] != 'b') )
        return 1;
    else
        return scanner3(x);
    return 0;
}

int scanner3(char *x){
    int i, j = 0;
    for(i=0; x[i] != '\0'; i++)
        if(x[i] != 'a' && x[i]!='b')
            return 0;

    char c;
    q0: c = x[j];
    if(c == 'a' || c == 'b'){
        j++;
        goto q1;
    }
    else
        return 0;
    q1: c = x[j];
    if((c == 'a' || c == 'b') && (i <= 5) ){
        j = i-3;
        goto q3;
    }
    else if((c == 'a' || c == 'b') && (i > 5) ){
        j++;
        goto q2;
    }
    else
        return 0;
    q2: c = x[j];
    if(c == 'a'){
        j = i-3;
        goto q3;
    }
    else
        return 0;
    q3: c = x[j];
    if(c == 'a'){
        j++;
        goto q4;
    }
    else
        return 0;
    q4: c = x[j];
    if(c == 'a' || c == 'b'){
        j++;
        goto q5;
    }
    else
        return 0;
    q5: c = x[j];
    if(c == 'a' || c == 'b')
        return 1;
    else
        return 0;
}

char *EntraString(){
    fflush(stdin);
    char tecla;
    char *retorno=NULL;
    int tam=0;
    do {
        tecla=getchar();
        if(!retorno)
            retorno=(char*)malloc(sizeof(char));
        else
            retorno=(char*)realloc(retorno,tam+1);
        if(tecla != '\n')
            retorno[tam]=tecla;
        tam++;
    } while(tecla!='\n');
    retorno[tam-1]='\0';
    return retorno;
}

int main(){
    printf("\nEntre com a palavra:\t");
    char *palavra = EntraString();
    if(scanner1(palavra))
        printf("\nPalavra reconhecida");
    else
        printf("\nPalavra nao reconhecida");
    return 0;
}
