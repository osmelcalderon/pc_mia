#include <stdint.h>
#include <stdio.h>

#define ull unsigned long long  // Max (+ ) 18,446,744,073,709,551,615 
#define ll  long long           // Max (+-) 9,223,372,036,854,775,807
#define ul  unsigned long       // Max (+ ) 4,294,967,295
#define l   long                // Max (+-) 2,147,483,647
#define u64 uint64_t            // Max (+ ) = ull
#define u32 uint32_t            // Max (+ ) = ul
#define u16 uint16_t            // Max (+ ) 65535
#define u8  uint8_t             // Max (+ ) 256
#define i64 int64_t             // Max (+-) = ll
#define i32 int32_t             // Max (+-) = l
#define i16 int16_t             // Max (+-) 32767
#define i8  int8_t              // Max (+-) 127
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)
#define si(t, o) t o; scanf("%d", (i32*)&o);
#define su(t, o) t o; scanf("%d", (u32*)&o);
#define si64(o) i64 o; scanf("%lu", &o);
#define su64(o) u64 o; scanf("%lu", &o);
#define si128(o) ll o; scanf("%llu", &o);
#define su128(o) ull o; scanf("%llu", &o);
#define start main

/**
 *         ___ ____  _         _  ___  
 *        / _ \___ \| |       | |/ _ \ 
 *  __  _| (_) |__) | |__   __| | | | |
 *  \ \/ /\__, |__ <| '_ \ / _` | | | |
 *   >  <   / /___) | |_) | (_| | |_| |
 *  /_/\_\ /_/|____/|_.__/ \__,_|\___/ 
 **/

void print_pile(u16* pile, u16 plen) {
	for (u16 len = plen; len > 0; len--) {
		printf("%d\n", pile[len - 1]);
	}
}

int start() {
	su(u32, N);
	u16 pile1[N]; u16 len1 = N;
	for (u16 n = N; n > 0; n--)
		pile1[N - n] = n;

	u16 pile2[N]; u16 len2 = 0;
	u16 pile3[N]; u16 len3 = 0;

	while (len1 > 0 || len2 > 0) {
		u32 D, C;
		scanf("%d %d", &C, &D);

		if (C == 2) {
			for (u16 x = 0; x < D; x++) {
				if (len2 == 0)
					break;
				pile3[len3] = pile2[len2 - 1];
				len3++;
				len2--;
			}
		} else if (C == 1) {
			for (u16 x = 0; x < D; x++) {
				if (len1 == 0)
					break;
				pile2[len2] = pile1[len1 - 1];
				len2++;
				len1--;
			}
		}
	}

	print_pile(pile3, len3);
	return 0;  // I always forget about this sh*t xDDD
}