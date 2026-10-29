#include <stdio.h>
#include <string.h>

int main() {
	char S[10000], O[10000]; scanf("%[^\n]", S);
	int L = strlen(S), I = 0;
	for (int x = 0; x < L; x++) {
		char c = S[x];
		if (c == ')') {
			char temp[10000]; int TI = 0;
			I--; while (O[I] != '(') {
				temp[TI] = O[I]; TI++; I--;
			}

			temp[TI] = '\0';
			for (int x = 0; x < TI; x++) {
				O[I] = temp[x]; I++;
			}
		} else {
			O[I] = S[x]; I++;
		}
	}

	O[I] = '\0';
	printf("%s\n", O);
}