#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

int32_t main(){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);std::cout.setf(std::ios::fixed);
    int n,k;
    std::string s;
    std::cin>>n;

    std::vector<std::string>li[25],car;
    std::map<std::string,bool>us;

    for(int i=0;i<n;i++){
        std::cin>>k;
        while(k--){
            std::cin>>s;
            li[i].push_back(s);
            if(!us[s]){
                us[s]=1;
                car.push_back(s);
            }
        }
    }
    for(int i=0;i<car.size();i++){
        for(int j=i+1;j<car.size();j++){
            bool a=0,b=0,c=0;
            for(int k=0;k<n;k++){
                bool x=0,y=0;
                for(int ki=0;ki<li[k].size();ki++){
                    if (li[k][ki]==car[i])x=1;
                    if (li[k][ki]==car[j])y=1;
                }
                if(x && y)a=1;
                else if(x)b=1;
                else if(y)c=1;
            }
            if(a && b && c){
                std::cout<<"no\n";
                return 0;
            }
        }
    }
    std::cout<<"yes\n";
    return 0;
}