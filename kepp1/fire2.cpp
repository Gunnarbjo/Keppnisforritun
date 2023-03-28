#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll,ll>>Vbooks;
ll books, ifire, tmp1, tmp2;

ll fbest(ll n, ll fire){
    if(n == 0 || fire < 0){
        return 0;
    }
    if(Vbooks[n].first > fire){
        return fbest(n-1,fire);
    }
    return max(fbest(n-1,fire),Vbooks[n].second+fbest(n-1,fire+Vbooks[n].second-Vbooks[n].first));
}

int main() {

    cin >> books >> ifire;
    Vbooks.reserve(books);

    for(ll i = 0; i < books; i++){
        cin >> tmp1 >> tmp2;
        Vbooks.push_back(make_pair(tmp1,tmp2));
        //cout << Vbooks[i].first << ' ' << Vbooks[i].second << '\n';

    }

    sort(Vbooks.begin(),Vbooks.end());

    ll clife = ifire, tlife = ifire , cnt = 0;
    for(ll i = 0; i < books; i++){
        if(Vbooks[i].first > clife) break;
        cnt++;
        tlife += Vbooks[i].second;
        clife += Vbooks[i].second-Vbooks[i].first;
    }
    cout << tlife+fbest(cnt, ifire) << '\n';
}