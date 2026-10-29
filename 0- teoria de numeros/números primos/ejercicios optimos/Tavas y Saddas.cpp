#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

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

#define int i32
#define start main

/**
 *         ___ ____  _         _  ___  
 *        / _ \___ \| |       | |/ _ \ 
 *  __  _| (_) |__) | |__   __| | | | |
 *  \ \/ /\__, |__ <| '_ \ / _` | | | |
 *   >  <   / /___) | |_) | (_| | |_| |
 *  /_/\_\ /_/|____/|_.__/ \__,_|\___/ 
 *  © 2020-2023 x93 All Rights Reserved
 **/

int start() {
	char input[10]; scanf("%s", input);
	int start = 0, sum = 2, len = strlen(input);

	if (len > 1) {
		for (int x = 0; x < len - 1; x++) {
			start += sum;
			sum *= 2;
		}
	} else {
		if (input[0] == '4')
			printf("1\n");
		else
			printf("2\n");
		return 0;
	}

	start++; char no[10];
	for (int x = 0; x < len; x++)
		no[x] = '4';
	no[strlen(input)] = '\0';

	while (strcmp(input, no) != 0) {
		if (no[len - 1] == '7') {
			int u7 = 1;
			no[len - 1] = '4';
			for (int y = 1; y < len; y++) {
				int ry = len - y - 1;
				if (no[ry] != '7')
					break;
				no[ry] = '4';
				u7++;
			}

			no[len - u7 - 1] = '7';
		} else if (no[len - 1] == '4') {
			no[len - 1] = '7';
		}

		start++;
	}

	printf("%d\n", start);
	return 0;  // I always forget about this sh*t xDDD
}