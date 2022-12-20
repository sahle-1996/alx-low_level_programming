#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Function to randomly generates password
 * of length N
 */
void randomPasswordGeneration(int N)

	int i = 0;

	int randomizer = 0;

	srand((unsigned int)(time(NULL)));

	char numbers[] = "0123456789";

	char letter[] = "abcdefghijklmnoqprstuvwyzx";

	char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";

	char symbols[] = "!@#$^&*?";

	char password[N];



	randomizer = rand() % 4;

	/* Iterate over the range [0, N] */

	for (i = 0; i < N; i++){
		if (randomizer == 1) {
			password[i] = numbers[rand() % 10];
			randomizer = rand() % 4;
			printf("%c", password[i]);

		}
		else if (randomizer == 2) {
			password[i] = symbols[rand() % 8];
			randomizer = rand() % 4;
			printf("%c", password[i]);

		}
		else if (randomizer == 3) {
			password[i] = LETTER[rand() % 26];
			randomizer = rand() % 4;
			printf("%c", password[i]);

		}
		else {
			password[i] = letter[rand() % 26];
			randomizer = rand() % 4;
			printf("%c", password[i]);
		}
	}
}

int main()

	/**
	 * Length of the password to
	 * be generated
	 */
	int N = 10;

	randomPasswordGeneration(N);

	return 0;

	}
