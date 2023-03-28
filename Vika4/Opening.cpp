#include <bits/stdc++.h>
typedef long long ll;
int main()
{
    ll inp, temp;
    std::vector<ll> myV;
    std::cin >> inp;
    for (ll i = 0; i < inp; i++)
    {
        std::cin >> temp;
        myV.push_back(temp);
    }
    std::sort(myV.begin(),myV.end());
    ll bomb = inp;
    for(ll i=0;i<inp;i++){
        bomb=std::min(bomb,myV[i]+inp-i-1);
    }
    std::cout<<bomb<<'\n';
}