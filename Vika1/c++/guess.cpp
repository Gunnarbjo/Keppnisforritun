#include <iostream>
#include <string>


int main(){
    int mid = 500;
    int low = 1;
    int max = 1001;
    std :: string resp;

    for(int i = 0; i < 10; i++){
        std :: cout << mid << "\n";
        std :: cin >> resp;

        if(resp[0] == 'c') break;
        if(resp[0] == 'l') max = mid;
        if(resp[0] == 'h') low = mid;

        mid = low + (max - low)/2;

    }
}