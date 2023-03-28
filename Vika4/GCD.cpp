#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll items,enemies,hp,dmg,temp,mdmg=0;
vector<ll>itemsV,enemiesV;
ll combat(ll low,ll high){
    ll icnt=low+((high-low)/2),sum=0;
    if(high==low) return itemsV[low];
    double temp=dmg+itemsV[icnt];
    for(auto x:enemiesV){
        sum+=(ceil(x/temp)-1);
        if(hp<=sum) break;
    }
    if(sum<hp) return combat(low,icnt);
    return combat(icnt+1,high);
}
main(){
    cin>>items>>enemies>>hp>>dmg;
    ll sum=0,sum2=0;
    itemsV.reserve(items);enemiesV.reserve(enemies);
    for(ll i=0;i<items;i++){
        cin>>temp;
        if(temp>mdmg)mdmg=temp;
        itemsV.push_back(temp);
    } 
    double dmg1=dmg,dmg2=dmg+mdmg;
    for(ll i=0;i<enemies;i++){
        cin>>temp;
        enemiesV.push_back(temp);
        sum+=(ceil(temp/dmg1)-1);
        sum2+=(ceil(temp/dmg2)-1);
    }
    if(sum<hp)cout<<"Veski Eyleifs er bjargad\n";
    else if(sum2>hp)cout<<"Nu er Eyleifur i bobba\n";
    else{sort(itemsV.begin(),itemsV.end());cout<<combat(0,items-1)<<'\n';}}