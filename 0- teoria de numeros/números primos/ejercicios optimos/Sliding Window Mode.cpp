#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int unsigned long long
#define endl '\n'

using namespace std;

const int MOD=1e9+7;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(0);
    cout<<fixed;
    //cout<<flush;
    int n,k;
    cin>>n>>k;
    vector<int> x(n);
    unordered_map<int,int> o;
    for (int i = 0; i < n; i++)
    {
        cin>>x[i];
    }
    int c=0,res;
    for (int i = 0; i < k; i++)
    {
        o[x[i]]++;
        if(o[x[i]]>c)
        {
            c=o[x[i]];
            res=x[i];
        }else
        if(o[x[i]]==c)
        {
            res=min(res,x[i]);
        }
    }
    cout<<res<<" ";
    for (int i = k; i < n; i++)
    {
        /*cout<<"  t_";
        for(auto e:o)
        cout<<e.first<<" "<<e.second<<",";
        cout<<"_t  ";
        cout<<x[i-k]<<" x[k-i]"<<k-i<<endl;*/
        o[x[i-k]]--;
        if(x[i-k]==res)
        {
            c--;
            for(auto l:o)
            {
                //cout<<" searching "<<l.first<<" "<<l.second<<endl;
                if(l.second>c)
                {
                    c=l.second;
                    res=l.first;
                }else
                if(l.second==c)
                {
                    res=min(res,l.first);
                }
            }
        }
        o[x[i]]++;
        if(o[x[i]]>c)
        {
            c=o[x[i]];
            res=x[i];
        }else
        if(o[x[i]]==c)
        {
            res=min(res,x[i]);
        }
        cout<<res<<" ";
    }cout<<endl;
    return 0;
}