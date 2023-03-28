#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int isPrime(ll num){
    if (num < 2) return 0;
    for (ll i = 2; i * i <= num; i++)
        if (num % i == 0) return 0;
    return 1;
}

int main(){
    ll numCases;
    cin >> numCases;

    for (ll i = 0; i < numCases; i++){
        ll input, sqrtUp;
        cin >> input;

        sqrtUp = ceil(sqrt(input));

        if (sqrtUp * sqrtUp == input){
            if (isPrime(sqrtUp)){
                cout << setw(18) << setfill('0') << input << "\n";
            }
        }
    }
}
