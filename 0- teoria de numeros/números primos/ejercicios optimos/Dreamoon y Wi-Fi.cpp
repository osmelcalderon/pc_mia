#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)
#define start main

/**
 *         ___ ____  _         _  ___  
 *        / _ \___ \| |       | |/ _ \ 
 *  __  _| (_) |__) | |__   __| | | | |
 *  \ \/ /\__, |__ <| '_ \ / _` | | | |
 *   >  <   / /___) | |_) | (_| | |_| |
 *  /_/\_\ /_/|____/|_.__/ \__,_|\___/ 
 **/

int pos(char* f, char* s, int* T, int* C) {
	int x = 0, y = 0;

	for (int e = 0; e < strlen(f); e++) {
		if (f[e] == '+')
			x++;
		else
			x--;
	}

	for (int e = 0; e < strlen(f); e++) {
		if (s[e] == '+') {
			y++;
		} else if (s[e] == '-') {
			y--;
		} else {
			char cpy[11];
			strcpy(cpy, s);
			cpy[e] = '+';
			pos(f, cpy, T, C);
			cpy[e] ='-';
			pos(f, cpy, T, C);

			return 0;
		}
	}

	(*T) += 1;
	if (x == y)
		(*C) += 1;
	return 0;
}

int start() {
	char first[11], second[11];
	scanf("%s %s", first, second);

	int T = 0, CP = 0;
	pos(first, second, &T, &CP);
	
	if (CP == 0)
		printf("%.9f\n", 0.f);
	else
		printf("%.9f\n", (float)CP / T);
	return 0;  // I always forget about this sh*t xDDD
}