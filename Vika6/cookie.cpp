#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

      string inp;
      priority_queue <int> max_pq;
      priority_queue <int, vector<int>, greater<int> > min_pq;
      int vali=0;

      while (cin>>inp){
          if(inp!="#"){
              vali = stoi(inp);
              if(min_pq.size()==0){
                  min_pq.push(vali);
              }
              else{
                    int medi=min_pq.top();
                    if(vali>medi){
                        min_pq.push(vali);
                        if(min_pq.size() > (max_pq.size()+1)){
                            medi = min_pq.top();
                            min_pq.pop();
                            max_pq.push(medi);
                        }
                    }
                    else{
                        max_pq.push(vali);
                        if(max_pq.size() > min_pq.size()){
                            int pqmax = max_pq.top();
                            max_pq.pop();
                            min_pq.push(pqmax);
                        }
                    }
              }
          }
          else{
               int medi = min_pq.top();
               min_pq.pop();
               if(min_pq.size()!=max_pq.size()){
                   int pqmax = max_pq.top();
                   max_pq.pop();
                   min_pq.push(pqmax);
               }
               cout<<medi<<'\n';
          }
      }
}
