#include <iostream>

int main(){
    std :: string inp;
    std :: string finstr;

    std ::cin >> inp;
    finstr = finstr + inp[0];

    for(int i = 1; i < inp.length(); i++){
        if(inp[i] == '-') finstr = finstr + inp[i + 1];
    }

    std :: cout << finstr << "\n";
}