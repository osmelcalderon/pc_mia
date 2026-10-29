#include<bits/stdc++.h> 
using namespace std;

// Macros para abreviar operaciones comunes
#define clr(a,val) memset(a,val,sizeof (a))  // Inicializar arreglo con un valor
#define fi first
#define se second
#define pb push_back
#define eps 1e-6

typedef long long ll;
const int INF=0x3f3f3f3f; // Constante para infinito (usada en DP o grafos)

// Función rápida de lectura de enteros
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

// Constantes y estructuras
const int N=1e5+10; // Máximo número de nodos
struct edge{
    int to,next; // Representa una arista (hijo, siguiente arista)
} a[N];

int head[N],cnt; // head[u] apunta al inicio de la lista de adyacencia de u
int n,Master;    // n = número de nodos, Master = raíz del árbol
int ls[N],rs[N],dis[N]; // Estructura de Leftist Heap (hijo izq, hijo der, distancia)
ll m,C[N],L[N],sum[N],sz[N],ans; 
// m = límite de salario
// C[i] = costo (salario) del nodo i
// L[i] = "nivel" o valor asociado al nodo i
// sum[i] = suma de salarios en el subárbol i
// sz[i] = tamaño del subárbol i
// ans = respuesta final (máximo valor alcanzado)

// Agregar arista (u -> v)
void addedge(int u,int v)
{
    a[++cnt]=(edge){v,head[u]};
    head[u]=cnt;
}

// Merge en Leftist Heap (fusión de dos montículos)
int Merge(int A,int B)
{
    if (!A||!B) return A+B;  // Si uno está vacío, devolver el otro
    if(C[A]<C[B]) swap(A,B); // El nodo con mayor C (salario) queda en la raíz
    rs[A]=Merge(rs[A],B);    // Fusionar por el hijo derecho
    if(dis[ls[A]]<dis[rs[A]]) swap(ls[A],rs[A]); // Mantener propiedad del Leftist Heap
    dis[A]=dis[rs[A]]+1;
    return A;
}

// Eliminar el tope del montículo (máximo)
int Delete(int A)
{
    return Merge(ls[A],rs[A]);
}

// Función DFS para procesar el árbol desde el "Master"
int dfs(int u)
{
    int A=u,B;
    sum[u]=C[u]; sz[u]=1; // Inicializar con los valores del propio nodo
    
    // Recorrer hijos de u
    for(int e=head[u];e;e=a[e].next)
    {
        int v=a[e].to;
        B=dfs(v);     // Recursión en el hijo
        A=Merge(A,B); // Fusionar los heaps
        sum[u]+=sum[v];
        sz[u]+=sz[v];
    }

    // Mientras la suma de salarios exceda el límite
    while(sum[u]>m)
    {
        sum[u]-=C[A]; // Restar el salario más alto
        sz[u]--;      // Reducir el tamaño del subárbol
        A=Delete(A);  // Quitar la raíz del heap
    }

    // Actualizar la respuesta máxima (nivel * tamaño del subárbol válido)
    ans=max(ans,L[u]*sz[u]);
    return A;
}

int main()
{
    n=read();m=read(); // Número de nodos y límite de salarios

    for(int i=1;i<=n;i++)
    {
        int u=read();       // Jefe inmediato (0 si es el Master)
        C[i]=read();        // Salario del nodo i
        L[i]=read();        // Nivel del nodo i
        if(!u) Master=i;    // Guardar raíz del árbol
        else addedge(u,i);  // Relación padre-hijo
    }

    dfs(Master); // Procesar desde la raíz
    printf("%lld",ans); // Imprimir la respuesta
    return 0;
}
