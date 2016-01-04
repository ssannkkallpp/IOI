/*
Solution to the bookshelves problem in ZCO-2016.
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;

int cmp(const void *a, const void *b) {
	return(*(int *)a - *(int *)b);
}

int min_skew(int *a, int *b, int n, int k);

int main(void) {
	int n, k;
	cin >> n >> k;
	int a[n], b[n];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];
	qsort(a,n,sizeof(int),cmp);
	qsort(b,n,sizeof(int),cmp);
	cout << min_skew(a,b,n,k) << endl;
	return 0;
}

int min_skew(int *a, int *b, int n, int k) {
	int m = max(a[n-1], b[n-1]);
	if(a[n-1] > b[n-1]) {
		if(a[0] > b[n-1]) return a[n-1] + b[n-1];
		else {
			int temp, j;	
			for(j=n-2;j>=0;j--) {
				if(a[j] < b[j]) temp = 0;
				else temp = 1;
			}
			// temp tells us from which array the swaps are going, 1 or 2
			if(temp == 0) {
				return m + a[n-1-k];
			} else return m + b[n-1-k];
		}
	} else {
		if(b[0] > a[n-1]) return a[n-1] + b[n-1];
		else {
			int temp, j;	
			for(j=n-2;j>=0;j--) {
				if(a[j] < b[j]) temp = 0;
				else temp = 1;
			}
			// temp tells us from which array the swaps are going, 1 or 2
			if(temp == 0) {
				return m + a[n-1-k];
			} else return m + b[n-1-k];
		}
	}
}
