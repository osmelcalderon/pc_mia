#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
     
int N, B, F[250], S[250], D[250], best = 9999;
bool beenthere[250][250];  // set of (location, boot) states we can reach

int solve(void)
{
   for (int b=0; b<B; b++) 
      for (int i=0; i<N; i++) {

         // Compute whether state (i, b) is reachable...
	
         if (F[i] > S[b]) { beenthere[i][b] = false; continue; } // invalid state; snow too deep

         if (i==0 && b==0) beenthere[i][b] = true;  // initial state

         // can we reach this state via forward step from some prior state?
         for (int i2=0; i2<i; i2++) 
            if (beenthere[i2][b] && i2+D[b]>=i) beenthere[i][b] = true;

         // can we reach this state via change of boot from some prior state?
         for (int b2=0; b2<b; b2++) 
            if (beenthere[i][b2]) beenthere[i][b] = true;

         // have we reached the end?  return smallest boot # we can achieve
         if (i==N-1 && beenthere[i][b]) return b;
      }
}
     
int main(void)
{
   //ifstream fin ("snowboots.in");
   //ofstream fout ("snowboots.out");
   
   cin >> N >> B;
   for (int i=0; i<N; i++) cin >> F[i];
   for (int i=0; i<B; i++) cin >> S[i] >> D[i];

   cout << solve() << "\n"; 
   return 0;
}