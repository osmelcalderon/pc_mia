#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
int n=1;
sort(s.begin(),s.end());
while(next_permutation(s.begin(),s.end())){
n++;
}
cout<<n;
do{
cout<<"\n"<<s;
}while(next_permutation(s.begin(),s.end()));
}