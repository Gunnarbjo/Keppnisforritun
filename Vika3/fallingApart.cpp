#include<bits/stdc++.h>
typedef long long ll;
main(){std::vector<ll> n;ll c,b=0,a=0,j=0,i=0,d;std::cin>>c;for(;j<c;j++){std::cin>>d;n.push_back(d);}std::sort(n.begin(),n.end());for(;i<c;i++){(i%2)?b+=n[(c-1)-i]:a+=n[(c-1)-i];}std::cout<<a<<" "<<b;}