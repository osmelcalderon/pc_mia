#include <vector>
#include<iostream>
#pragma GCC optimize("Ofast")
#define fast std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);std::cout.setf(std::ios::fixed);std::cout.precision(0);

int main(){fast;
    int n,maxx=0;
    std::cin>>n;
    std::vector<int>r(n+1,0);
    for(int i=1;i<n;i++){
        int a,b;
        std::cin>>a>>b;
        r[a]++;r[b]++;
        if(r[a]>maxx)maxx=r[a];
        if(r[b]>maxx)maxx=r[b];
    }
    std::cout<<maxx+1;
    return 0;
}