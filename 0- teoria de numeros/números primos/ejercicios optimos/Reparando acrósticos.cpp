#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;cin>>n;
    int minx=INT_MAX,miny=INT_MAX,maxx=INT_MIN,maxy=INT_MIN;
    while(n--)
    {
        int l,f,c;bool d;
        cin>>l>>f>>c>>d;
        if(d)
        {
            miny=min(miny,f);
            maxy=max(maxy,f+l);
        }
        else
        {
            minx=min(minx,c);
            maxx=max(maxx,c+l);
        }
    }
    cout<<maxy-miny<<' '<<maxx-minx;
    return 0;
}