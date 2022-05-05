# include <time.h>
# include <stdio.h>
# include <stdlib.h>
int main(void)
{
	 /* Length of the password */
	 unsigned short int length = 8;
	 /* Seed number for rand() */
	 srand((unsigned int) time(0));
	 /* ASCII characters 33 to 126 */
	 while (length--) {
	 putchar(rand() % 94 + 33);
	 }
	 printf("\n");
	 return 0;
} 

