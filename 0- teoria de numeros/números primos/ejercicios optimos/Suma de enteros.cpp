#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int unsigned long long
#define endl '\n'

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(0);
    cout<<fixed;
    //cout<<flush;
    int n;
    cin>>n;
    int medio,c=1,ini=1,fin=1e9+1;
    while(ini<=fin)
    {
        medio=(ini+fin)/2;
        //cout<<medio<<" "<<n<<endl;
        if((medio*(medio+1))/2<n)
        {ini=medio+1;}else
        {fin=medio-1;}
    }
    medio--;
    
    while((medio*(medio+1))/2<n)
    medio++;
    medio--;
    //cout<<medio<<endl;
    if(n-(medio*(medio+1))/2>medio)
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<medio<<" "<<n-(medio*(medio+1))/2<<endl;
    return 0;
}