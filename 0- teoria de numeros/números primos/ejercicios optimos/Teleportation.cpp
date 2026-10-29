#include <bits/stdc++.h>
using namespace std;

int N;
map<int,int> slopechg;   // slopechg[t] is how much the slope of f(y) changes when y=t

int main(void){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

   long long current_f = 0, slope_f = 0, current_y = -2000000000;

   cin >> N;
   for (int i=0; i<N; i++) {
      int a, b;
      cin >> a >> b;
      current_f += abs(a-b);

      // Now add any slope change breakpoints...
      if (abs(a) > abs(a-b)) continue;
      slopechg[b]+=2;
      if (a<b && a<0)   { slopechg[0]--; slopechg[2*b]--; }
      if (a<b && a>=0)  { slopechg[2*b-2*a]--; slopechg[2*a]--; }
      if (a>=b && a<0)  { slopechg[2*b-2*a]--; slopechg[2*a]--; }
      if (a>=b && a>=0) { slopechg[0]--; slopechg[2*b]--; }
   }

   // Now scan y forward and apply slope changes to trace out f(y), keeping track of min
   long long min_f = current_f;
   for (auto p : slopechg) {
      int new_y = p.first, delta_slope = p.second;
      current_f += slope_f * (new_y - current_y);
      current_y = new_y;
      slope_f += delta_slope;
      min_f = min(min_f, current_f);
   }

   cout << min_f << "\n";
   return 0;
}