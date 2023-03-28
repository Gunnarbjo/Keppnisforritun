#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum(vector<ll>& valV,ll l) {
    ll total=0;
    for(ll i=l;i>0;i&=i-1){
        total+=valV[i-1];
    }
    return total;
}
 
void update(vector<ll>& valV,ll l,ll value) {
    for(ll i=l;i<valV.size();i|=i+1) {
        valV[i]+=value;
    }
}

ll getValues(vector<ll>& valV,ll l) {
    return sum(valV,l+1)-sum(valV,l);
}

int main() {
    ll n, k;
    cin>>n>>k;
    vector<ll> valV(n+1,0);
    for(ll i=0;i<k;i++) {
        char c;
        cin>>c;
        if(c=='F'){
            ll x;
            cin>>x;
            ll val=getValues(valV,x);
            if(val==0){
                val=1;
            }
            else{
                val=-1;
            }
            update(valV,x,val);
            val=getValues(valV,x);
        }
        if(c=='C'){
            ll x, y;
            cin>>x>>y;
            cout<<sum(valV,y+1)-sum(valV,x)<<'\n';
        }
    }
}