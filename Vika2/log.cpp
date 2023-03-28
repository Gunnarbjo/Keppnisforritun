#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <list>

int spaces(std:: string word){
    return std :: count(word.begin(),word.end(),' ');
}

int main(){
    int a;
    std :: cin >> a;
    std :: list<std :: string> :: iterator it;

    for(int i = 0; i < a; i++){
        std :: list<std :: string>wlist;
        int b;
        std :: string band;
        std :: cin >> b;
        std ::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std :: getline(std::cin,band);
        std :: cout << band << ":\n";
        int blen =band.length()-spaces(band);
        for(int j = 0; j < b; j++){
            std:: string song;
            std :: getline(std::cin,song);
            if(blen == (song.length()-spaces(song))){
                wlist.push_back(song);
            }
        }
        wlist.sort();
        for(it = wlist.begin();it != wlist.end();it++){
            std:: cout << *it << "\n";
        }
        
    }
    
}