#include <stdio.h>
#include <string.h>
#define MAXD 18

int main(){
	int suma, size, one, two, resto;
	suma = size = one = two = resto = 0;
	char num[MAXD];
	
	scanf("%s", &num);
	size = strlen(num);
	
	for(int i = 0; i < size; i++){
		suma += num[i] - '0';
		if((num[i] - '0') % 3 == 1) one++;
		else if((num[i] - '0') % 3 == 2) two++;
	} resto = suma % 3;
	
	if(resto == 0) printf("0");
	else if(resto != 0 && size < 2) printf("-1");
	else if(resto == 1){
		if(one > 0 && (size - 1) > 0) printf("1");
		else if(two > 1 && (size - 2) > 0) printf("2");
		else printf("-1");
	}
	else{
		if(two > 0 && (size - 1) > 0) printf("1");
		else if(one > 1 && (size - 2) > 0) printf("2");
		else printf("-1");
	}
	
	return 0;
}