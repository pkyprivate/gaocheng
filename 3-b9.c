//2151753 º∆ø∆ ≈Ì¿§”Ó
#include <stdio.h>
int main() 
{
	int i, j, k;
	for (i = 1; i < 10; i++) {
		for (j = 1; j <= i; j++) {
			k = i * j;
			printf("%dx%d=%-4d",i,j,k);
			
		}
		printf("\n");
	}
	return 0;
}