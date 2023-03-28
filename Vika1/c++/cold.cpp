#include <iostream>

int main(){
    int a, temp;
    int cnt = 0;
    std :: cin >> a;

    for(int i = 0; i < a; i++){
        std :: cin >> temp;
        if(temp < 0) cnt++;
    }
    std :: cout << cnt << "\n";

    return 0;
}
