#include "stdio.h"
#include "vector"
#include "algorithm"
#define mx int(1e6) 
using namespace std; 
 
int max(int a, int b) {
    return (a<b) ? b : a; 
}
 
int main() {
     int n; scanf("%d", &n); 
     vector<int> sol_a, sol_b; 
     int m=0, c=0, rs=0; 
     
     for(int i=1; i<=n; i++) {
         int a, b; scanf("%d%d", &a, &b); 
         
         sol_a.push_back(a); 
         sol_b.push_back(b); 
     }
     
     sort(sol_a.begin(), sol_a.end()); 
     sort(sol_b.begin(), sol_b.end()); 
     
     int i=0, j=0; 
     while(i!=n && j!=n) {
         if(sol_a[i]<sol_b[j]) { c++; i++; }
         else { c--; j++; }
         
         rs=max(c, rs); 
     }
     
     printf("%d", rs);     
}