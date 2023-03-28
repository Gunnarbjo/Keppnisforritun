#include <bits/stdc++.h>

using namespace std;

unsigned long long perfectNumbers[] = {
    6ull,
    28ull,
    496ull,
    8128ull,
    33550336ull,
    8589869056ull,
    137438691328ull,
    2305843008139952128ull,
    2658455991569831744654692615953842176ull,
    191561942608236107294793378084303638130997321548169216ull,
    13164036458569648337239753460458722910223472318386943117783728128ull,
    14474011154664524427946373126085988481573677491474835889066354349131199152128ull
};

bool isInArray(unsigned long long n)
{
    int size = sizeof(perfectNumbers) / sizeof(perfectNumbers[0]);
    for (int i = 0; i < size; i++) {
        if (perfectNumbers[i] == n)
            return true;
    }
    return false;
}

void perfect(int n)
{
    if (isInArray(n))
    {
        printf("%d perfect\n", n);
        return;
    }

    int sq = (int)sqrt(n) + 1;
    int sum = 1;
    for (int i = 2; i < sq; i++)
    {
        if (n % i == 0)
        {
            int other = n / i;
            if (i != other) sum += other;
            sum += i;
        }
    }
    printf(sum == n ? "%d perfect\n" : (abs(sum - n) < 3) ? "%d almost perfect\n" : "%d not perfect\n", n);
}

int main()
{
    int n;
    while (cin >> n) perfect(n);
    return 0;
}
