#include <stdio.h>
#include <math.h>
using namespace std;
float dist(float a,float b,float c,float d){
    a-=c;b-=d;
    return abs(a*a)+abs(b*b);
}
int main(){
    int n;
    scanf("%d",&n);
    std::pair<int,int>ar[n];
    for(auto&i:ar)scanf("%d%d",&i.first,&i.second);
    int a=0,b=0;
    float m=100000000;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(dist(ar[i].first,ar[i].second,ar[j].first,ar[j].second)<m){
                a=i;
                b=j;
                m=dist(ar[i].first,ar[i].second,ar[j].first,ar[j].second);
            }
        }
    }
    printf("%d %d",a+1,b+1);
}