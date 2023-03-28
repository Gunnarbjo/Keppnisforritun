#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

long long recur(vector<long long>& v,ll b, ll sum){
    vector<ll>x;
    if(v.size()==b){sort(v.begin(),v.end());return v[b-1];}
    if(b%2==0){
        for(ll i=0; i<x.size();i+=2){
            x.push_back(v[i]+v[i+1]);
        }
        if(v.size()%2!=0){
            x.push_back(v[v.size()-1]);
        }    
    }else{
        cout<<"later";
    }
    ll p=recur(x,b,sum);
    return p;
}


int main(){
    ll a,b,c,e,sum=0;
    vector<ll>v;
    cin>>a>>b;
    for(ll i=0;i<a;i++){
        cin>>c;
        sum+=c;
        v.push_back(c);
    }
    sum/=b;

    cout<<recur(v,b,sum);

}