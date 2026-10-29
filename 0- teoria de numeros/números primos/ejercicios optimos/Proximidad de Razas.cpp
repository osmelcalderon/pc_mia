#include <cstdio>
#include <algorithm>

using namespace std;

#define NMAX 50005

struct Cow {
	int breedID;
	int x;
	bool operator<(Cow const& o) const {
		if (breedID == o.breedID) {
			return x < o.x;
		} else {
			return breedID > o.breedID;
		}
	}
};
Cow cows[NMAX];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		cows[i].x = i;
		scanf("%d", &cows[i].breedID);
	}

	sort(cows, cows + n);

	for (int i = 1; i < n; i++) {
		if (cows[i].breedID == cows[i-1].breedID && cows[i].x - cows[i-1].x <= k) {
			printf("%d\n", cows[i].breedID);
			return 0;
		}
	}

	printf("-1\n");
}