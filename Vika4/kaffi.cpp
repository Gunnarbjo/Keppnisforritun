#include<bits/stdc++.h>
typedef long long ll;

ll func(ll room,ll size){
    return room-(size%room);
}
main(){
    ll inp, temp,max=0, sum=0;
    std::vector<ll>myV;
    std::cin>>inp;
    for(ll i=0;i<inp;i++){
        std::cin>>temp;
        if(temp>max) max=temp;
        myV.push_back(temp);
    }
    for(ll i=0;i<inp;i++){
        for(ll j=0;j<inp;j++){
            max=std::min(max,func(myV[i],myV[j]));
            std::cout<<max<<'\n';
        }
        
    }
    for(auto x:myV){
        sum+=x%max;
    }
    std::cout<<sum<<'\n';
}   

