
#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int main()
{

    ll a, b, inp;

    while (true)
    {
        std ::vector<ll> dragon;
        std ::vector<ll> knights;
        ll cnt = 0, coins = 0, it = 0;
        std ::cin >> a >> b;
        if (a == 0 && b == 0)
            break;

        for (ll i = 0; i < a; i++)
        {
            std ::cin >> inp;
            dragon.push_back(inp);
        }
        for (ll i = 0; i < b; i++)
        {
            std ::cin >> inp;
            knights.push_back(inp);
        }

        if (a > b)
        {
            std ::cout << "Loowater is doomed!\n";
            continue;
        }

        std ::sort(dragon.begin(), dragon.end());
        std ::sort(knights.begin(), knights.end());

        for (auto x : dragon)
        {
            if(it == knights.size()) break;
            for (; it < b; it++)
            {
                
                if (x <= knights[it])
                {
                    coins += knights[it];
                    cnt++;
                    it++;
                    break;
                }
            }
            if (cnt == a)
                break;
        }
        if (cnt == a){
            std ::cout << coins << "\n";
        }
        else{
            std ::cout << "Loowater is doomed!\n";
        }
    }
}