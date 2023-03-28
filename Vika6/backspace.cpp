#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string a;
    vector<char>w(a.length());
    getline(cin,a);
    for(ll i=0;i<a.length();i++){
        if(a[i]=='<') w.pop_back();
        else w.push_back(a[i]);
    }
    
    cout << string_view(w.data(), w.size()) <<'\n';
}