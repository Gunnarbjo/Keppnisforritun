#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>inpV;
ll csum=0,bsum=0,devi=1000;
ll calc(ll i,ll j){
    if(i<0) return bsum;
    if(j<0){
        csum=0;
        return calc(i-1,i-1);
        }
    csum+=inpV[j];
    if(csum>1000){
        if(csum-1000<=devi){
            if(csum>bsum){
                bsum=csum;
                devi=bsum-1000;
            }
        }
        csum-=inpV[j];
        return calc(i,j-1);
    }
    if(1000-csum<devi){
        bsum=csum;
        devi=1000-csum;
        
    }
    return calc(i,j-1);
}
int main(){
    
    ll inp,temp;
    cin>>inp;

    for(ll i=0;i<inp;i++){
        cin>>temp;
        inpV.push_back(temp);
    }
    sort(inpV.begin(),inpV.end());
    cout<<calc(inp-1,inp-1)<<"\n";
}