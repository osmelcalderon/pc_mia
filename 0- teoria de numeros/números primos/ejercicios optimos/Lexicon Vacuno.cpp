#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define dd long double
#define ll long long
#define pb push_back
#define pii pair<int , int>
#define pll pair<ll,ll>
#define pdd pair<dd,dd>
#define fst first
#define snd second
#define vi vector<int>
#define vii vector<pii>
#define fr(i,a,b) for(ll (i) = (a); (i) <= (b); (i)++)

const int talla=2e5;
const double pi=acos(-1.0);
const double EPS=1e-15;
const ll inf=1e18;

///Implement!!!
int BS(vi &vec, int X){

    ///vec is in descending order
    int l=0,r=(int)vec.size()-1;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(vec[mid]<X){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}
///Complejidad: L*W*25*log(L)
void solve(){
//    21:56 pm
    int W, L;
    cin>>W>>L;
    string mensaje;cin>>mensaje;
    mensaje="#"+mensaje;

    vector<string>cowDictionary(W+1);
    for(int i=1;i<=W;i++){
        cin>>cowDictionary[i];
        ///Para que todos los strings sean 1-indexing
        cowDictionary[i]="#"+cowDictionary[i];
    }
    vi dp(L+1,0);

    vector<vi> posicionesChar(27);
    for(int i=(int)mensaje.size()-1;i>=1;i--){
        posicionesChar[mensaje[i]-'a'].pb(i);
    }

    ///Analize if the following binary search is
    ///doable using builtin lower and upper bounds:
    ///Given a decreasing ordered array a value X,
    ///find the position of the first element that
    ///is <=X

    for(int i=1;i<=L;i++){
        ///caso en el que esa letra se elimina
        dp[i]=dp[i-1]+1;

        for(int k=1;k<cowDictionary.size();k++){
            if(cowDictionary[k].back()!=mensaje[i])continue;
            int curr_pos=i;
            for(int r=(int)cowDictionary[k].size()-2;r>=1;r--){
                char c=cowDictionary[k][r];
                int index=BS(posicionesChar[c-'a'],curr_pos);

                if(index==-1){
                    curr_pos=-1;
                    break;
                }
                curr_pos=posicionesChar[c-'a'][index];
            }
            if(curr_pos!=-1){
                ///Dp transition
                dp[i]=min(dp[i],dp[curr_pos-1]+(i-curr_pos+1)-((int)cowDictionary[k].size()-1));
            }
        }
    }
    cout<<dp[L];

}

signed main(){
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   cout.setf(ios::fixed);cout.precision(12);
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int t=1;
   //cin>>t;
   while(t--){
      solve();
      cout<<"\n";
   }
   return 0;
}