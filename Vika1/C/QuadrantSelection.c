#include <stdio.h>

int main(){

    int a, b;
    scanf("%d %d", &a, &b);

    if(a > 0){
        if(b > 0) printf("%d\n",1);
        else printf("%d\n",4);
    }
    else{
        if(b > 0) printf("%d\n", 2);
        else printf("%d\n",3);
    }

    return 0;
}