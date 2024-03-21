#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_largest_char(char *str, int len);
int multiply_chars(char *str, int len);
int generate_random_char(int seed);

int f4(char *usrn, int len);
int f5(char *usrn, int len);

int main(int argc, char **argv)
{
	char keygen[7];
	int len, ch;
	long alph[] = { 0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
					0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
					0x723161513346655a, 0x6b756f494b646850 };

	if (argc != 2)
		return (1);

	for (len = 0; argv[1][len]; len++)
		;

	keygen[0] = ((char *)alph)[(len ^ 59) & 63];
	keygen[1] = ((char *)alph)[(find_largest_char(argv[1], len) ^ 79) & 63];
	keygen[2] = ((char *)alph)[(multiply_chars(argv[1], len) ^ 85) & 63];
	keygen[3] = ((char *)alph)[(f4(argv[1], len) ^ 14) & 63];
	keygen[4] = ((char *)alph)[(f5(argv[1], len) ^ 239) & 63];
	keygen[5] = ((char *)alph)[(generate_random_char(*argv[1]) ^ 229) & 63];
	keygen[6] = '\0';

	for (ch = 0; keygen[ch]; ch++)
		putchar(keygen[ch]);

	return (0);
}

int find_largest_char(char *str, int len)
{
	int max = *str;
	int i;

	for (i = 0; i < len; i++)
	{
		if (str[i] > max)
			max = str[i];
	}

	return max;
}

int multiply_chars(char *str, int len)
{
	int product = 1;
	int i;

	for (i = 0; i < len; i++)
		product *= str[i];

	return product;
}

int generate_random_char(int seed)
{
	srand(seed);
	return rand() % 26 + 'a';
}

int f4(char *usrn, int len)
{
	int ch;
	int vch;
	unsigned int rand_num;

	ch = *usrn;
	vch = 0;

	while (vch < len)
	{
		if (ch < usrn[vch])
			ch = usrn[vch];
		vch += 1;
	}

	srand(ch ^ 14);
	rand_num = rand();

	return (rand_num & 63);
}

int f5(char *usrn, int len)
{
	int ch;
	int vch;

	ch = vch = 0;

	while (vch < len)
	{
		ch = ch + usrn[vch] * usrn[vch];
		vch += 1;
	}

	return (((unsigned int)ch ^ 239) & 63);
}
