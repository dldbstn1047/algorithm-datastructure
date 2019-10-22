/*
	백준 11004 - k 번째수
*/
#include <iostream>
using namespace std;
typedef long long LL;
#define N 5000000
#define BASE (LL) 1e10

int n;
LL a[N + 1];
int search(int start, int end) {
	int i = start;
	int j = end;
	LL pivot = a[start];

	while (i < j) {
		while (a[i] <= pivot && i <= end) { i++; }
		while (a[j] >= pivot && j > start) {  j--; }
		if (i < j) {
			LL tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	LL tmp = a[j];
	a[j] = a[start];
	a[start] = tmp;

	return j;
}
LL quick_select(int start, int end, int k) {
	int idx;
	if (start <= end) {
		idx = search(start, end);
		if (idx == k) return a[idx];
		else if (k < idx) {
			quick_select(start, idx - 1, k);
		}
		else {
			quick_select(idx + 1, end, k);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += BASE;
	}
	LL ret = quick_select(1, n, k) - BASE;
	cout << ret;

	return 0;
}
