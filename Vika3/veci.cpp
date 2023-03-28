#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
int main(){
    int inp,w;
    std :: vector<ll>nums;
    std :: vector<ll>comb;

    std :: cin >> inp;
    w = inp;
    while(w > 0){
        int temp = w%10;
        nums.push_back(temp);
        w /= 10; 
    }
    std :: sort(nums.begin(),nums.end());

    do{
        int a = 0;
        for(auto x: nums){
            a=(a+x)*10;
        }
        a /= 10;
        comb.push_back(a);
    }while(std :: next_permutation(nums.begin(),nums.end()));

    int cnt = 0;
    for(auto x: comb){
        cnt++;
        if(x == inp){
            if(cnt < comb.size()) std :: cout << comb[cnt] << "\n";
            else std :: cout << 0 << "\n";
        }
    }
}