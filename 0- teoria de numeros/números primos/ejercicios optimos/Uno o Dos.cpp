#include<iostream>
//escrito en el paradero d camiones pa Matanzas
using namespace std;
int A[100005];
int Encontrar(int a){
if(A[a] == a)return a;
return A[a] = Encontrar(A[a]);
}
void Unir(int a, int b){
a = Encontrar(a);
b = Encontrar(b);
if(a == b)return;
if(a>b)swap(a, b);
A[b] = a;
}
int main(){
int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i <= n; i++)A[i] = i;
    for(int i = 0, a, b, c; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        Unir(a, b);
        }
    int respuesta = 0;
    for(int i = 1; i <= n; i++)
       if(i == Encontrar(i))respuesta++;
    printf("%d", respuesta);
}