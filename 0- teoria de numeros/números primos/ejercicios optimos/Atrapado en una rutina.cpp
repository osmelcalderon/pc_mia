#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
#define opt ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout.setf(ios::fixed);cout.precision(0);
#define rall(x) (x).rbegin(),(x).rend()
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pq priority_queue
#define int long long
#define pb push_back
#define main main()
#define fr front()
#define bk back()
#define ss second
#define endl "\n"
#define tp top()
#define pp pop()
#define fs first
#define ph push
#define oo 50
#define md 1e9

using namespace std;

int n;
map<int,int >x,y,cant;
map<int,char>di;

struct crash{
  int i,j,disti,distj,moving;
};crash c[(oo+1)*(oo+1)];

void aux();

main{
    cin>>n;
    for(int i=0;i<n;i++)cin>>di[i]>>x[i]>>y[i];

    aux();

    for(;;){
        int best=-1;
        for(int i=0; i<oo*oo; i++){
            if(c[i].moving&&(best==-1||c[i].disti<c[best].disti))
            best=i;
        }
        if(best==-1)break;
        if(cant[c[best].i]==0&&(cant[c[best].j]==0||cant[c[best].j]>c[best].distj))cant[c[best].i]=c[best].disti;
        c[best].moving=0;
    }

    for (int i=0; i<n; i++){
        if(!cant[i])cout<<"Infinity"<<endl;
        else cout<<cant[i]<<endl;
    }
}

void aux(){
    int act=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(di[i]==di[j])continue;

            int xi=x[i],yi=y[i],xj=x[j],yj=y[j];

            if(di[i]=='E'){
                swap(xi,yi);
                swap(xj,yj);
            }
            if(yi>yj || xi<xj || xi>=(xj+yj-yi)) continue;

            c[act]={i,j,abs(yj-yi),abs(xi-xj),1};
            act++;
        }
    }
}/*


#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
#define opt std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);std::cout.precision(0);

//  Functions :
#define dbgp(v) for(auto i : (v))cout<<i.fs<<" , "<<i.ss<<"\n";
#define dbgi(v) for(auto i : (v))cout<<i<<"\n";
#define rall(v) v.rbegin(),v.rend()
#define all(v)  v.begin(),v.end()
#define size(v) ((int)v.size())

//  Error types :
#define rte std::vector<int>rtt(oo);
#define wa std::cout<<"d";
#define tle while(1){;}
#define ir exit(1);

//  Data structures :
#define pii std::pair<int,int>
#define vii std::vector<pii>
#define vi std::vector<int>

//  Data structures manipulation :
#define pb push_back
#define ss second
#define fs first
#define ph push

//   Pointers :
#define fr front()
#define bk back()
#define pp pop()

//   Constants :
const int oo=1e18;
const int lm=1e18;
const int md=1e9;

using namespace std;

int32_t main()
{
    opt;



    return 0;
}


*/