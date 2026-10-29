#include <cstdio>
#include <cstring>

const int maxn=100;

char s[maxn+2];
int have[2][30],ans,n;

int main()
{
  scanf("%d%s",&n,s+1);
  for(int i=1; i<n; ++i)
    {
      memset(have,0,sizeof have);
      int cnt=0;
      for(int j=1; j<=i; ++j)
        {
          have[0][s[j]-'a'+1]=1;
        }
      for(int j=i+1; j<=n; ++j)
        {
          have[1][s[j]-'a'+1]=1;
        }
      for(int j=1; j<=26; ++j)
        {
          if(have[0][j]&&have[1][j])
            {
              ++cnt;
            }
        }
      if(cnt>ans)
        {
          ans=cnt;
        }
    }
  printf("%d\n",ans);
  return 0;
}