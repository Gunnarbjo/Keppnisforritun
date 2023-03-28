#include <stdio.h>

int main(){

    int a, temp;
    int b = 0;

    scanf("%d", &a);
    
    for(int i = 0; i < a; i++){
        scanf("%d",&temp);
        if( temp < 0) b++;
    }    
    printf("%d\n", b);

    return 0;
}