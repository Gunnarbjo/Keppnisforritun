#include<iostream>

int test(int a){int b=0;std::cin>>a;b=a%10;a=a/10;(a<b)?a=a*10+b:a=b*10+a;std::cout<<a<<"\n";}
main(){for(int i=1;i<100;i++){test(i);}}