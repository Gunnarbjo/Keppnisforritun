#include <iostream>

int main(){

    int a, b;

    std :: cin >> a;
    std :: cin >> b;

    if(a > 0){
        if(b > 0) std :: cout << 1 << "\n";
        else std :: cout << 4 << "\n";
    }
    else{
        if(b > 0) std :: cout << 2 << "\n";
        else std :: cout << 3 << "\n";
    }

}