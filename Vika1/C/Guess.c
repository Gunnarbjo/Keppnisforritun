#include <stdio.h>

int main(){
    int mid = 500;
    int low = 1;
    int max = 1001;
    char resp[7];

    for(int i = 0; i < 10; i++){
        printf("%d\n",mid);
        fflush(stdout);
        scanf("%s", resp);
        if(resp[0] == 'c') return 0;
        if(resp[0] == 'l'){
            max = mid;  
        }
        if(resp[0] == 'h'){
            low = mid;
        }
        mid = low + (max - low)/2;
    }
    return 0;
}