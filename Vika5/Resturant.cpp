#include <bits/stdc++.h>
const int MX_N = 111;
const int MX_S = 30003;
const int INF = 1000000;
int N, S;

int memo[MX_N][MX_S];
int a[MX_N];

int num_ways(int k, int w) {
    if (w < 0) {
        return 0;
    }
    if (k == N) {
        return w == 0;
    }
    if (memo[k][w] != -1) {
        return memo[k][w];
    }
    int without_k = num_ways(k+1, w);
    int with_k = num_ways(k, w-a[k]);
    return memo[k][w] = without_k + with_k;
}

void print_path(int k, int w) {
    if (k == N) {
        return;
    }
    int without_k = num_ways(k+1, w);
    int with_k = num_ways(k, w-a[k]);
    if (without_k > 0) {
        print_path(k+1, w);
    }
    if (with_k > 0) {
        printf("%d ", k+1);
        print_path(k, w-a[k]);
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    int tot = 0;
    for (int i = 0; i < N; i++) {
        tot += a[i];
    }
    memset(memo, -1, sizeof(memo));

    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &S);
        int ans = num_ways(0, S);
        if (ans == 0) {
            puts("Impossible");
        } else if (ans == 1) {
            print_path(0, S);
            putchar('\n');
        } else {
            puts("Ambiguous");
        }
    }
    return 0;
}
