
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<string>vec;
ll bou[2];
ll cha[2];
string saved="Heill a hufi\n",fail="Ponnukaka\n";
ll Row,line,cnt=0;
array<ll,2> rolling(ll i,ll j, char way,char itm){
    cout<<i<<" "<<j<<" "<<itm<<" "<<way<<"\n";
    if(itm=='B'&&i==cha[0]&&j==cha[1])return{i,j};
    if(vec[i][j+1]=='S'&&itm=='B'&&way=='r')return rolling(i,j+1,way,itm);
    if(vec[i][j-1]=='S'&&itm=='B'&&way=='l')return rolling(i,j-1,way,itm);
    if(vec[i+1][j]=='.') rolling(i+1,j,way,itm);
    if(vec[i+1][j]=='#'&& way=='n')return {i,j};    
    if(vec[i+1][j]=='\\') return rolling(i+1,j+1,'r',itm);
    if(vec[i+1][j]=='/') return rolling(i+1,j-1,'l',itm);    
    if((vec[i][j-1]=='#'&&way=='l'))return {i,j};
    cout<<i<<" "<<j<<"\n";
    if((vec[i][j+1]=='#' && way=='r')){return {i,j};};
    if((vec[i][j+1]=='\\'&&way=='r')||(vec[i][j-1]=='/'&&way=='l'))return {i,j};
    if(vec[i][j+1]=='/' && way=='r') return rolling(i,j-1,'l',itm);
    if(vec[i][j-1]=='\\' && way=='l') return rolling(i,j+1,'r',itm);
    if(way=='r') return rolling(i,j+1,way,itm);
    return rolling(i,j-1,way,itm);
}
int main(){
    ll bi=-1,bj=-1,si=-1,sj=-1;
    string temp;
    cin>>Row>>line;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for(ll i=0;i<Row;i++){
        getline(cin,temp);
        vec.push_back(temp);
        if(bi==-1||si==-1){
            for(ll j=0;j<temp.length();j++){
                if(temp[j]=='B'){bi=i;bj=j;}
                if(temp[j]=='S'){si=i;sj=j;}
            }
        }
    }
    array<ll,2> S=rolling(si,sj,'n','S');
    array<ll,2> B=rolling(bi,bj,'n','B');
    cout<<S[0]<<B[1]<<" "<<S[0]<<S[1];
    if(B[0]==S[0]&&B[1]==S[1])cout<<fail;
    else cout<<saved;

}
