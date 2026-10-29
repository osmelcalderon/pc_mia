#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
//#define pb push_back
#define f first
#define s second
//#define all(x) (x).begin(), (x).end()
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,b;
    scanf("%d%d",&n,&b);
    vector<int>xs;
    vector<int>ys;
    vector<pair<int,int>>xy(n);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        xs.push_back(x+1);
        ys.push_back(y+1);
        xy[i].f=x;
        xy[i].s=y;
    }
    int xst=xs.size();
    int yst=ys.size();

    sort(xs.begin(),xs.end());
    sort(ys.begin(),ys.end());
    for(int i=0;i<xst-1;i++){
        if(xs[i]==xs[i+1])
            {xs.erase(xs.begin()+i);i--;xst--;}
    }
    for(int i=0;i<yst-1;i++){
        if(ys[i]==ys[i+1])
            {ys.erase(ys.begin()+i);i--;yst--;}
    }
    int m=n;
	int d=n/4;
	if(n%2)d++;
    for(int i=0;i<xst-1&&m!=d;i++){
        int x=xs[i];
        for(int j=0;j<yst-1;j++){
            int y=ys[j];
            int s1=0,s2=0,s3=0,s4;

            for(pair<int,int>p:xy){
                if(p.f<x){
                	if(p.s<y)s1++;
                	else s2++;
				}
				else if(p.s<y)s3++;
            }
            s4=n-s1-s2-s3;
            int m1,m2,m3;
            m1=max(s1,s2);
            m2=max(s3,s4);
            m3=max(m1,m2);
            m=min(m,m3);
        }
    }
    cout<<m;
    return 0;
}