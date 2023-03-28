#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    int a , unused1, unused2;
    char str[7];
    int cnt = 0;
    int flag = 0;

    unused1 = scanf("%d", &a);

    for(int i = 1; i <= a;i++){
        unused2 = scanf("%s", str);

        if(strcmp(str, "mumble") != 0 && atoi(str) != i)flag++;
       
        strcpy(str,"");
    }   
        if(flag > 0) printf("something is fishy\n");
        else printf("makes sense\n");

    return 0;
}