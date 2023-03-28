#include <iostream>
#include <string>

int main(){
    std::string board[5];
    int cnt = 0;
    bool flag = false;

    for (int i = 0; i < 5; i++){
        std::cin>>board[i];
    }

    for (int i = 0; i < 5; i++){
        if(flag)break;
        for (int j = 0; j < 5; j++){
            if(board[i][j] == 'k'){
                cnt++;
                if(i + 2 < 5 && j - 1 > 0 && board[i + 2][j - 1] == 'k'){flag = true;break;}
                if(i + 1 < 5 && j - 2 > 0 && board[i + 1][j - 2] == 'k'){flag = true;break;}
                if(i + 1 < 5 && j - 2 > 0 && board[i + 1][j - 2] == 'k'){flag = true;break;}
                if(i + 2 < 5 && j - 1 > 0 && board[i + 2][j - 1] == 'k'){flag = true;break;}
            } 
        }  
    }
    if(cnt != 9)flag = true;
    if(flag) std::cout<<"invalid\n";
    else std::cout<<"valid\n";
}