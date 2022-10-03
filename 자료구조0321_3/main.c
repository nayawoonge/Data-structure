#include <stdio.h>
#define ROWS 3
#define COLS 3

void matrix_add(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS])
{
	for (int r = 0;r < ROWS;r++)
		for (int c = 0;c < COLS;c++)
			C[r][c] = A[r][c] + B[r][c];
}
void matrix_print(int A[ROWS][COLS])
{
	int c;
	for (int r = 0;r < ROWS;r++)
	{
		for (c = 0;c < COLS;c++)
		{
			printf("%d", A[r][c]);
			if (c < 2)
				printf(",");
		}
		printf("\n");
	}
	printf("---------\n");
	
}

int main(void)
{
	int array1[ROWS][COLS] =
	{ 
		{2,3,0},
		{8,9,1},
		{7,0,5} 
	};
	int array2[ROWS][COLS] =
	{
		{2,3,0},
		{8,9,1},
		{7,0,5}
	};
	int array3[ROWS][COLS];

	matrix_add(array1, array2, array3);
	matrix_print(array1);
	matrix_print(array2);
	matrix_print(array3);
	return 0;
}
