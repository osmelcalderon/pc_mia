#include<stdio.h>
#include<vector>
using namespace std;

//Variables globales
char idata[100000][20];
int dataLens[100000];
int dataLen=0;
vector<int> prefixes1[26];
vector<int> prefixes2[26*26];
vector<int> prefixes3[26*26*26];
vector<int> prefixes4[26*26*26*26];

int min(int a, int b) {return a<b ? a : b;}

int count_for(char what[21], int whatLen, int prefx){
    int cnt = 0;

    int sz;
    for(int ref : prefixes4[prefx]){
        sz = dataLens[ref];
        if(sz<whatLen)continue;
        bool flag = true;
        for(int i = 4; i<whatLen; i++){
            if( idata[ref][i] != what[i] ){
                flag=false; break;
            }
        }
        cnt += flag?1:0;
    }
    return cnt;
}

/* Funcion principal author: ~k4r3l_dev*/
int main(){
    int q; scanf("%d ", &q);
    char what[21];

    while(q--){
        scanf("%s", what);
        if(what[0] == 'a'){
            scanf("%s", idata[dataLen]);
            dataLens[dataLen]=20;
            for(int i = 0; i<20; i++){
                if(idata[dataLen][i] == 0){dataLens[dataLen] = i; break;}
            }
            int accum = 0;
            for(int i = 0; i<min(dataLens[dataLen], 4); i++){
                accum*=26;
                accum+=idata[dataLen][i] - 'a';
                switch(i){
                    case 0: prefixes1[accum].push_back(dataLen); break;
                    case 1: prefixes2[accum].push_back(dataLen); break;
                    case 2: prefixes3[accum].push_back(dataLen); break;
                    case 3: prefixes4[accum].push_back(dataLen); break;
                }
            }
            dataLen++;
        }else{
            scanf("%s", what);
            int wlen = 20;
            for(int i = 1; i<21; i++)
                if(what[i]==0){wlen=i; break;}
            int minlen = min(4, wlen);
            int cnt;
            int prefx = 0;
            for(int i = 0; i<minlen; i++){
                prefx*=26; prefx+=what[i]-'a';
            }


            switch(wlen){
                case 1: cnt=prefixes1[prefx].size(); break;
                case 2: cnt=prefixes2[prefx].size(); break;
                case 3: cnt=prefixes3[prefx].size(); break;
                case 4: cnt=prefixes4[prefx].size(); break;
                default: cnt=count_for(what, wlen, prefx);
            }
            printf("%d\n", cnt);
        }
    }
}