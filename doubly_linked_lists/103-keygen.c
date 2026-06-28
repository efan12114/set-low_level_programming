#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_first_three(char *password, const char *codex, int len, char *arg);
void generate_last_three(char *password, const char *codex, int len, char *arg);

/**
 * main - Generates and prints passwords for the crackme5 executable.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char password[7], *codex;
	int len;

	if (argc != 2)
		return (1);

	codex = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	len = strlen(argv[1]);

	generate_first_three(password, codex, len, argv[1]);
	generate_last_three(password, codex, len, argv[1]);

	password[6] = '\0';
	printf("%s", password);
	return (0);
}

/**
 * generate_first_three - Generates the first 3 characters of the password.
 * @password: Array storing the password.
 * @codex: The lookup string cipher table.
 * @len: Length of the username argument.
 * @arg: The username string.
 */
void generate_first_three(char *password, const char *codex, int len, char *arg)
{
	int i, temp;

	temp = (len ^ 59) & 63;
	password[0] = codex[temp];

	temp = 0;
	for (i = 0; i < len; i++)
		temp += arg[i];
	password[1] = codex[(temp ^ 79) & 63];

	temp = 1;
	for (i = 0; i < len; i++)
		temp *= arg[i];
	password[2] = codex[(temp ^ 85) & 63];
}

/**
 * generate_last_three - Generates the last 3 characters of the password.
 * @password: Array storing the password.
 * @codex: The lookup string cipher table.
 * @len: Length of the username argument.
 * @arg: The username string.
 */
void generate_last_three(char *password, const char *codex, int len, char *arg)
{
	int i, temp;

	temp = 0;
	for (i = 0; i < len; i++)
	{
		if (arg[i] > temp)
			temp = arg[i];
	}
	srand(temp ^ 14);
	password[3] = codex[rand() & 63];

	temp = 0;
	for (i = 0; i < len; i++)
		temp += (arg[i] * arg[i]);
	password[4] = codex[(temp ^ 239) & 63];

	for (i = 0; i < arg[0]; i++)
		rand();
	password[5] = codex[(rand() ^ 229) & 63];
}
