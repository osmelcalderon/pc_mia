/**Exactly K times by Leonardo16**/
    #include<bits/stdc++.h>
    #define ll long long
    using namespace std;
    const ll base=311ll;
    string s;
    ll k,h[10000],p[10000],n,sa[10000];


    void build(){
        h[0]=0;
        p[0]=1;
        sa[0]=0;
        for(int i=1;i<s.size();i++){
            sa[i]=i;
            h[i]=h[i-1]*base+s[i];
            p[i]=p[i-1]*base;
        }
    }

    ll get_hash(int a,int b){
        return h[b]-h[a-1]*p[b-a+1];
    }

    ll lcp(int i,int j){
        ll lo=0,best=0,hi=min(n-i+2,n-i+2);
        while(lo+1<hi){
            ll mid=(lo+hi)/2;
            if(get_hash(i,i+mid-1)==get_hash(j,j+mid-1)){
                lo=mid;
                best=lo;
            }else{
                hi=mid;
            }
        }
        return best;
    }

    bool cmp(int i,int j){
        ll l=lcp(i,j);
        return s[i+l]<s[j+l];
    }
    int main(){
        ios_base::sync_with_stdio(0);cin.tie(0);
        cin>>k;
        k--;
        cin>>s;
        s='$'+s;
        s+='$';
        n=s.size();
        build();
        sort(sa,sa+n,cmp);
        ll ans=-1;
        if(k==0){cout<<n-2;return 0;}
        for(int i=2;i+k<n;i++){
            ll l=lcp(sa[i],sa[i+k]);
            if(l!=0)
                if(lcp(sa[i],sa[i-1])<l){
                    if(i+k-1==n-1||lcp(sa[i+k],sa[i+k+1])<l){
                        ans=max(ans,l);
                    }
                }
        }
        cout<<ans;
    return 0;}