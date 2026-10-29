#include <stdio.h>
#include <string.h>

#define MAXN 200000
#define MAXL 26

long long o[MAXL];
char c[MAXN];

int main(){
	memset(o, 0, sizeof o);
	long long ans = 0;
	
	scanf("%s", &c);
	
	int size = strlen(c);
	o[c[size - 1] - 'a']++;
	for(int i = size - 2; i > 0; i--){
		int act = c[i] - 'a';
		if(c[i] == c[i - 1] && c[i] != c[i + 1]){
			ans += (size - 1) - i - o[act];
			memset(o, 0, sizeof o);
			o[act] = (size - 1) - i + 2;
			i--;
		}
		else o[act]++;
	}
	
	printf("%lld", ans);
	
	return 0;
}