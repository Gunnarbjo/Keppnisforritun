#include <iostream>
#include <string>

int main(){
    int a;
    int flag = 0;
    std :: string inp;
    std :: cin >> a;

    for(int i = 1; i <= a ; i++){
        std :: cin >> inp;
        if(inp != "mumble" && atoi(inp.c_str()) != i) flag++;
    }
    if(flag > 0) std :: cout << "something is fishy\n";
    else std :: cout << "makes sense\n";
}