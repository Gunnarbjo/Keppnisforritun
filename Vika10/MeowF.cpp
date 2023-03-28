#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull isqrt(ull n) {
    ull x = n;
    ull y = (x + 1) / 2;
    while (y < x) {
        x = y;
        y = (x + n / x) / 2;
    }
    return x;
}

map<ull, ull> factor(ull n) {
    map<ull, ull> m;
    ull sqrtn = isqrt(n);
    for(ull i = 2; i <= isqrt(n); i++) {
        while(n % i == 0) {
            if(m.find(i) != m.end()) {
                m[i]++;
            } else {
                m[i] = 1;
            }
            n /= i;
            sqrtn = isqrt(n);
        }
    }
    if(n > 1) {
        m[n] = 1;
    }
    return m;
}

int main() {
    ull n;
    cin >> n;

    map<ull, ull> m = factor(n);
    ull ans = 1;
    for(auto& i : m) {
        while(i.second >= 9) {
            i.second -= 9;
            ans *= i.first;
        }
    }
    cout << ans << "\n";

    return 0;
}
