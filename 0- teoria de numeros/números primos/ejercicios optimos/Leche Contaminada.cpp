#include<stdio.h>
#include<vector>
#pragma GCC optimize("Ofast")
#define endl "\n"
#define fs first
#define sd second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>

using namespace std;

int main() {
    short n,m;
    int d,s,p,l,t;
    pii ans= {0,0};
    scanf("%i %i %d %d",&n,&m,&d,&s);
    bool ma[51][51]={};
    vpii v[m+1];
    vi sick(m+1,0);
    for(int i=0; i<d; i++) {
        scanf(" %d %d %d",&p,&l,&t);
        if(ma[p][l]!=1) {
            ma[p][l]=1;
            v[l].pb({p,t});
        }
    }
    for(int i=0; i<s; i++) {
        scanf(" %d %d",&p,&t);
        for(int j=1; j<=m; j++) {
            for(int h=0; h<v[j].size(); h++) {
                if(v[j][h].fs==p && v[j][h].sd<t) {
                    sick[j]++;

                }
            }
            if(ans.fs<sick[j]) {
                        ans.fs=sick[j];
                        ans.sd=j;
                    }
        }

    }
    int o=v[ans.sd].size();
    printf("%d\n",o);
    return 0;
}