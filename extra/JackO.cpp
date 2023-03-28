#include <iostream>

typedef long long ll;
typedef unsigned long long ull;
unsigned Choose( ull n, ull k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    ll result = n;
    for( ll i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main(){
    ll a,b,c;

    std :: cin >> a >> b >> c;

    std :: cout << Choose(a,1) * Choose(b,1) * Choose(c,1) << "\n";
}