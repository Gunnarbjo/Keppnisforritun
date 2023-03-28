#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(){

    int a;
    std :: vector<int>iList;
    std :: vector<int>cList;
    std:: cin >> a;

    //to take in and count at the same time
    for(int i = 0; i < a; i++){
        int b;
        bool flag = false;
        std::cin>>b;
        for(int j = 0;j < iList.size();j++){
            if(iList[j] == b){
                cList[j] = cList[j] + 1;
                flag = true;
                break;
            }
        }
        if(!flag){
            iList.push_back(b);
            cList.push_back(1);
        } 
    }
    std::sort(cList.begin(),cList.end());
    int sum = 0;
    int cnt = cList.size();

    for(auto x:cList){
        sum = cnt * x;
        cnt--;
    }
    std::cout<<sum<<"\n";

}