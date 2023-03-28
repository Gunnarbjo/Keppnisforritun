#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void calc(vector<ll>&li){
    for(ll i=1;i<li.size()-2;i++){
        if(li[i-1]<li[i]&&li[i]<li[i+1]){
            cout<<li[i-1]<<' '<<li[i]<<' '<<li[i+1]<<'\n';
            return;
        }
    }
    cout<<-1<<'\n';
    return;
}

int main(){
    ll inp,temp;
    cin>>inp;
    vector<ll>ninp;

    for(ll i=0;i<inp;i++){
        cin>>temp;
        ninp.push_back(temp);
    }
    calc(ninp);
}