#include<iostream>
#include <set>
#include <vector>
main(){int s,w,d,i=0,k=0;std::set<long long>p;std::vector<long long>a;std::cin>>s>>w;p.insert(s);for(;k<w;k++){std::cin>>d;a.push_back(d);p.insert(d);p.insert(s-d);}for(;i<w;i++){for(int j=i+1;j<w;j++){p.insert(a[j]-a[i]);}}for(auto x:p){std::cout<<x<<' ';}}