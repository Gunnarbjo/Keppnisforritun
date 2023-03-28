#include <bits/stdc++.h>
typedef long long ll;

ll items, enemies, hp, dmg, temp, mdmg = 0;
std::vector<ll> itemsV;
std::vector<ll> enemiesV;
std::string savedG("Veski Eyleifs er bjargad\n");
std::string failed("Nu er Eyleifur i bobba\n");

ll combat(ll icnt){
    ll sum = 0;
    icnt++;
    if(icnt >= (items-1)) return itemsV[items-1];
    for(auto &x : enemiesV){
        sum += (ceil(x / (dmg + itemsV[icnt])) - 1);
        if(hp <= sum) break;
    }
    if(sum < hp) return itemsV[icnt];
    return combat(icnt);
}

int main(){
    std::cin >> items >> enemies >> hp >> dmg;
    for(ll i = 0; i < items; i++){
        std::cin >> temp;
        itemsV.push_back(temp);
    } 
    for(ll i = 0; i < enemies; i++){
        std::cin >> temp;
        enemiesV.push_back(temp);
    }
    
    std::sort(itemsV.begin(), itemsV.end());
    mdmg = itemsV[items - 1];

    ll sum = 0, sum2 = 0;
    for(auto x : enemiesV){
        sum += (ceil(x / dmg) - 1);
        sum2 += (ceil(x / (dmg + mdmg)) - 1);
    }
    if(sum < hp){
        std::cout << savedG;
    }
    else if(sum2 >= hp){
        std::cout << failed;
    }else{
        ll answ = combat(0);
        std::cout << answ << '\n';
    }    
}
