/*#pragma GCC optimize(" unroll-loops")
#pragma gcc optimize("Ofast")
#pragma GCC optimization("Ofast")
#pragma optimize(Ofast)*/
#include<stdio.h>
#include<string.h>

int min(int a,int b){
	return a > b ? a : b;
}

char str[75];
int MX_1=0,MN_1;
int MX_2=0,ind_2;

int tam_1=0;
    void manacher_op1(char str[]) {
    int n = strlen(str);
    int p[n]={0};
    
    int c = 0, r = 0;
    for (int i =1; i < n-1; i++){
    	
        int j = c - (i-c) ;
        if (r > i) p[i] = min(r-i , p[j]);
        
        
        while (str[i+1+p[i]] == str[i-1-p[i]]){
        	
            p[i]++;
        if (i+p[i] > r) {
            c = i;
            r = i+p[i];
            
        }
		if(i-p[i]<0){
			p[i]--;
			break;
		}
		}
        
        if(p[i]>MX_1){
        	MX_1=i+p[i];
        	MN_1=i-p[i];
        	tam_1=MX_1-MN_1;
		} 
        
    }
}
int tam=0;
void manacher_op2(char str[]) {
    int n = strlen(str);
    int p[n]={0};

    for (int i =1; i < n-1; i++){
        
        while (str[i+1+p[i]] == str[i-p[i]]){
        	
            p[i]++;
        if (i-p[i] < 0) {
            break;
            
        }
		}
        
        
        if(p[i]>MX_2){
        	MX_2=p[i];
        	ind_2=i;
        	tam=(i+p[i])-(i-p[i]);
		} 
    }
}

#define EduarSr main

int EduarSr(){
	
	scanf("%s",str);
	
	manacher_op1(str);
	manacher_op2(str);

	if(tam_1>tam){
	for(int i=MN_1;i<=MX_1;i++){
		
		printf("%c",str[i]);
	}
		
	}else {
	for(int i=ind_2-MX_2+1;i<=ind_2;i++){
		printf("%c",str[i]);
	}
	for(int i=ind_2+1;i<=ind_2+MX_2;i++){
		printf("%c",str[i]);
	}
	
	}
	
}