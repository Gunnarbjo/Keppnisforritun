#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> dmg;
vector<ll> life;
ll books, ifire, tmp1, tmp2;

ll fbest(ll n, ll fire){
    if(n == books || fire < 0){
        return 0;
    }
    else if(fire-dmg[n]<0){
        return fbest(n+1, fire);
    }
    ll temp1 = fbest(n+1, fire);
    fire=(fire-dmg[n])+life[n];
    ll temp2 = life[n] + fbest(n+1,fire);
    return max(temp1, temp2);
}

int main() {

    cin >> books >> ifire;
    dmg.resize(books);
    life.resize(books);

    for (ll i = 0; i < books; i++) {
        cin >> tmp1 >> tmp2;
        dmg[i] = tmp1;
        life[i] = tmp2;
    }
    cout << ifire+fbest(0, ifire) << '\n';
}
