/*
	백준 2751 - 수 정렬하기 2
*/

#include <stdio.h>

#define N (int)1e6

int n;
int a[N];
int ret[N];
int cnt[N * 2 + 1];
void count_sort() {
	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
	}

	for (int i = 1; i < (N * 2 + 1); i++) {
		cnt[i] += cnt[i - 1]; //i 숫자가 등장하는 마지막 인덱스를 가지고 있다.
	}

	for (int i = n - 1; i >= 0; i--) {
		ret[--cnt[a[i]]] = a[i];
	}
}
int main(void) {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i] += N;
	}

	count_sort();
	for (int i = 0; i < n; i++) {
		printf("%d\n", ret[i]- N);
	}
	return 0;
}
