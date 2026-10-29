#include <bits/stdc++.h>
int f(int n){
    int r=0;
    n*=10;
    std::vector<int>v;
    while(n/=10){
        v.push_back(n%10);
    }
    sort(v.begin(),v.end());
    for(int i:v){
        r*=10;
        r+=i;
    }
    return r;
}
int32_t main(){
    int n;
    std::cin>>n;
    int r=0;
    while(n!=0){
        r++;
        n-=f(n);
    }
    std::cout<<r;
}