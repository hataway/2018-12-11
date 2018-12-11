#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *f = fopen(argv[1], "r");
	char rname[] = "memo.rev";
	FILE *rev = fopen(rname, "w");

	char txt;
	int ent = 0, space = 0, ch = 0;

	while ((txt = getc(f)) != EOF)
	{
		if (txt == '\n')
			ent++;

		else if (txt == 32)
			space++;

		else if (txt >= 33 && txt <= 126)
		{
			ch++;

			if (txt >= 65 && txt <= 90)
			{
				txt = txt + 32;
			}

			else if (txt >= 97 && txt <= 122)
			{
				txt = txt - 32;
			}
		}
		putc(txt, rev);
	}
	printf("<<Count Result>>\n");
	printf("Line Count :\t\t%d\n", ent + 1);
	printf("Word Count :\t\t%d\n", space + ent + 1);
	printf("Character Count :\t%d\n", ch);
	printf("File saved in %s\n", rname);

	fclose(f);
	fclose(rev);

	return 0;
}