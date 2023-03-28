#include <iostream>
#include <map>
#include <vector>
#include<algorithm>

typedef ll ll;
int main(){

    ll a;
    std::cin>>a;
    std::map<ll,ll> kdict;
    //std::map<ll, ll> vdict;
    std::vector<ll> it;

    for(ll i = 0; i < a; i++){
        ll b;
        std::cin>>b;
        if(kdict.count(b) != 0){
            kdict.at(b)= kdict.find(b)->second +1;
        }else{
            kdict.insert(std::pair<long long, long long>(b,1));
        }
    }
    for(auto pair:kdict){
        it.push_back(pair.second);
    }
    std::sort(it.begin(),it.end());

    ll sum = 0;
    ll cnt = it.size();
    for(ll i = 0; i <it.size();i++){
        sum += it[i] * cnt;
        cnt--;
    }
    std::cout<<sum<<"\n";
}