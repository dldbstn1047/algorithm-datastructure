/*
	백준 2751 - 수정렬하기 2
	N ( 1<= N <=1,000,000 ) 정렬
*/
#include <stdio.h>
#define N 1000000

int a[N];
int tmp[N]; //여유 공간이 필요한 단점
int n;
void merge(int start, int end) {
	int i = start;
	int k = start;
	int mid = (start + end) /2 ;
	int j = mid + 1;

	while (i <= mid  && j <= end) {
		if (a[i] < a[j]) {
			tmp[k++] = a[i++];
		}
		else {
			tmp[k++] = a[j++];
		}
	}
	int t = i <= mid ? i : j; //i 가 남았나?
	while (k <= end) {
		tmp[k++] = a[t++];
	}
	for (int i = start; i <= end; i++) {
		a[i] = tmp[i];
	}
}
void mergesort(int start, int end) {

	if (end <= start)
		return;

	int mid = (start + end) / 2;
	mergesort(start, mid);
	mergesort(mid + 1, end);
	merge(start, end);
}
int main(void) {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	mergesort(0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}

	return 0;
}
