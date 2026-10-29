#include<bits/stdc++.h>
#define reg register
#define int long long
inline int read(){
    reg int x=0,k=1; reg char ch=getchar();
    while (ch<'0'||ch>'9') (ch=='-')&&(k=-1),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*k;
}
inline int min(reg int x,reg int y){return x<y?x:y;}
const int N=1e6+10;
int n,a[N],b[N];
signed main(){
	n=read();
	for (reg int i=0;i<n;i++) a[i]=read(),b[i]=read();
	for (reg int T=0;T<n+n+33;T++){
		reg int i=T%n,j=(i+1)%n,d;
		if (a[i]<b[i]) continue;
		if (!b[i]) a[j]+=a[i]/2,a[i]%=2;
		else d=(a[i]-b[i]+1)/2,a[j]+=d,a[i]-=d*2;
	}
	for (reg int i=0;i<n;i++) if (a[i]^b[i]) return puts("No"),0;
	puts("Yes");
	return 0;
}
