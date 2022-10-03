#include <stdio.h>
#define ROWS 3
#define COLS 3

void matrix_print(int A[ROWS][COLS])
{
	for (int i = 0;i < ROWS;i++)
	{
		for (int j = 0;j < COLS;j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
	printf("=========================\n");
}
void matrix_add(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS])
{
	for (int i = 0;i < ROWS;i++)
		for (int j = 0;j < COLS;j++)
			C[i][j] = A[i][j] + B[i][j];
}


int main(void) {
	int array1[ROWS][COLS] = { { 2,3,0 },
				  { 8,9,1 },
				  { 7,0,5 } };
	int array2[ROWS][COLS] = { { 2,3,0 },
				  { 8,9,1 },
				  { 7,0,5 } };

	int array3[ROWS][COLS];

	matrix_add(array1, array2, array3);
	matrix_print(array1);
	matrix_print(array2);
	matrix_print(array3);

	return 0;
}
