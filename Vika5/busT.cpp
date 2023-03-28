#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>myV;
ll ntr=0,sum=0,st,pt,dur,inp,temp;
ll calc(ll i){
    if(i>=inp) return 0;
    ll csum=0,cnt=0;
    while(csum<dur){
        if(i+cnt>=inp)break;
        if(myV[i+cnt]>=dur){
            cnt-=1;
            break;
        }
        csum+=myV[i+cnt];
        cnt++;
    }
    if(cnt>=ntr)sum+=pt;
    else sum+=cnt*st;
    return(calc(i+cnt));
}

int main(){
    
    cin>>st>>pt>>dur>>inp;
    for (ll i = 0; i < inp; i++){
        std::cin >> temp;
        myV.push_back(temp);
    }
    ntr=floor((pt*1.0)/st);
    ll price=inp*st;
    calc(0);
    price=min(price,sum);
    std::cout<<price<<'\n';

}