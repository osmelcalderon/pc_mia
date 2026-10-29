#include <stdio.h>

int main(){
	int n, ID[1000], ans = 0;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &ID[i]);
	
	for(int i = 0; i < n - 1; i++){
		int tam = 1, act = ID[i], dif = -1;
		for(int j = i + 1; j < n; j++){
			if(ID[j] == act) tam++;
			else if(dif == -1) dif = ID[j];
			else if(ID[j] != dif) break;
			if(tam > ans) ans = tam;
		}
	}
	
	printf("%d", ans);
	
	return 0;
}