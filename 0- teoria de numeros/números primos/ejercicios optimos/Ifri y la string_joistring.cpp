/*
 * Ifri y la string
 * https://dmoj.uclv.edu.cu/problem/joistring
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200001

template<int max, typename T = int>
struct Stack{
    T elements[max];
    int size=0;

    T push(T elem){
        elements[size++]=elem;
        return elem;
    }

    T pop(){
        return elements[--size];
    }

    T operator[](int at){
        return elements[at];
    }
};

int n, k;
char string[MAX];
int prevsJ[MAX];
int prevsO[MAX];
int prevsI[MAX];

/* Acumula las letras dadas */
int accum(char c, int *prevs, int start){
    int fst = -1;
    int cnt = 0, i, min;

    for(i = start; i<n; i++){
        prevs[i]=-1;
        if(string[i]==c){
            cnt++;
            if(fst == -1)fst=i;
            if(cnt==k){
                prevs[i]=fst;
                break;
            }
        }
    }

    min = i;
    if(i == n)return -1;

    for(i+=1; i<n; i++){
        if(string[i] == c){
            //Incrementar el segundo puntero
            for(fst+=1; string[fst]!=c; fst++){}
        }
        prevs[i]=fst;
    }

    return min;
}

/* Verifica la solucion para el final dado */
int check(int pos){
    int fst = prevsI[pos];
    fst = prevsO[fst-1];
    fst = prevsJ[fst-1];
    return fst;
}

/* Soluciona el testcase */
int solve(){

    int prev = accum('J', prevsJ, 0);
    if(prev==-1)return -1;
    prev = accum('O', prevsO, prev+1);
    if(prev==-1)return -1;
    prev = accum('I', prevsI, prev+1);
    if(prev==-1)return -1;

    int min=99999999, res;

    for(int i = prev; i<n; i++){
        res = i-check(i)+1;
        if(res<min){
            min=res;
            //printf("(%d-%d=%d)-%d-%d-%d\n", i, i-min, min, prevsI[i], prevsO[prevsI[i]], prevsJ[prevsO[prevsI[i]]]);
        }
    }
    return min - 3*k;
}

int main(){
    scanf("%d%d", &n, &k);
    scanf(" %[^\n]s", string);
    
    printf("%d", solve());
}
