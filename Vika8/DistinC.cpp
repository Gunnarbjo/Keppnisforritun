#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef vector<ll>vi;
typedef vector<vi>vvi;

vvi G;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  ll n,k,total,res=0;
  string str;
  cin>>n>>k;
  total=1<<k;
  G.resize(total);
  for(ll i=0;i<total;++i){
    for(ll j=0;j<k;++j){
      G[i].push_back(i^(1<<j));
    }
  }
  queue<ll>Q;
  vi vis(total,0);
  while (n--){
    cin>>str;
    ll v=0;
    for(char c:str)v=2*v+c-'0';
    Q.push(v),vis[v]=1;
  }
  while(!Q.empty()){
    res=Q.front(),Q.pop();
    for(ll nn:G[res]){
        if(!vis[nn]){
           vis[nn] = 1, Q.push(nn); 
        } 
    }
  }
  for(ll i = k; i--;){
    cout<<((res&(1 << i))? '1':'0');
    }
   
  cout<<'\n';
}