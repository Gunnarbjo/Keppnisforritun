#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

/*
    pre: iList is a vector of sorted numbers
    does: c is the highest nr of same numbers, 
          d is the number that is the most of
          cnt is the current count of the current nr being checked 
    post: c is the number of items removed from the list

*/
/*void looppty(std :: vector<int> &iList){
    int c = 0,d,cnt = 0;

    for(int i = 1; i < iList.size();i++){
        // if the nr before the checked nr is the same 
        if(iList[i-1]== iList[i]){
            cnt++;
        }else{
            // if the highest counted nr is smaller than the currently counted
            if(cnt > c){
                d = iList[i-1];
                c = cnt;
            }
            // if the c is the same but the currently counted nr is bigger
            else if(cnt == c && d < iList[i-1]){
                d = iList[1-1];
            }
            //resets current count
            cnt = 0;
        }
    }
    // removes the highest counted nr (d) from the list.
    iList.erase(std :: remove_if(iList.begin(),iList.end(),[=](int x){return x == d;}), iList.end());
}
*/

void testeroo(int &sum, std::vector<int>&cList){
    if(cList.size() > 0){
        sum = sum + std::accumulate(cList.begin(), cList.end(), 0);
        cList.pop_back();
        //std::cout<<cList[0]<<cList[1]<<cList[2]<<sum<<"\n";
        testeroo(sum,cList);
    }
    return;
}
int main(){
    int a,b;
    std :: vector<int>iList;
    std :: vector<int>cList;
    std :: cin >> a;

    //Taking n number of int's into vector
    for(int i = 0; i < a;i++){
        std :: cin >> b;
        iList.push_back(b);
    }
    //sorting so it's easyer to find same nr
    std :: sort(iList.begin(),iList.end());

    //First print of full list
    //int sum = 0;
    
    //looping untill we have only 1 number
    /*while(iList.size() > 2){
        looppty(iList);
        sum = sum + iList.size();
        std:: cout << sum << "\n";
    }*/
    int cnt = 1;
    for(int i = 1; i < iList.size();i++){
        if(iList[i-1]== iList[i]) cnt++;
        else {
            cList.push_back(cnt);
            cnt = 1;
        }
    }
    cList.push_back(cnt);
    std :: sort(cList.begin(),cList.end());

    /*int it = cList.size();
    for(int i = 0; i < it;i++){
        ;
        cList.pop_back();
    } */
    //int sum = std::accumulate(cList.begin(), cList.end(), 0);
    int sum = 0;
    testeroo(sum,cList);
    std :: cout << sum <<"\n";
}

