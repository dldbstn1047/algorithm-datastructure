/*
	백준 2750 - 수 정렬하기
	N ( 1 <= N <= 1000) 정렬
*/
#include <stdio.h>
#define N 1000

int n;
int a[N];
void quicksort(int start, int end) {
	if (start < end) {
		int pivot = a[start];
		int i = start ;
		int j = end;
		int tmp;
		while (i < j) {
			while (a[i] <= pivot && i <= end) i++;
			while (a[j] >= pivot && j > start ) j--;

			if (i < j) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}

		tmp = a[j];
		a[j] = a[start];
		a[start] = tmp;

		quicksort(start, j - 1 );
		quicksort(j + 1, end);
	}


}
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	quicksort(0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}
