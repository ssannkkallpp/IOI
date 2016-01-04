/*
Solution to the Bamboo art problem in ZCO-2016
The complexity of the algorithm is slightly on the higher side for the Subtask 2.
I will optimise it soon.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))

using namespace std;

int cmp(const void *a, const void *b) {
	return(*(int *)a - *(int *)b);
}
int ls(int *a, int n, int k);

int main(void) {
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	qsort(a, n, sizeof(int), cmp);
//	for(int i=0;i<n;i++) cout << a[i] << " " << b[i] << endl;
	cout << ls(a, n, a[n-1] - a[0]) << endl;
	return 0;
}

int ls(int *a, int n, int k) {
//	cout << k << endl;
	int V[n][k], f, go; /*
	This dp table Vij = max such sequence until element i with common difference
	j
	Vi0 = 1 as no two elements are the same in the array
	V0j = 1 -> obviously
	Vij = for f < i and Ai - Af = j, Vij = Vfj + 1, break! as only 
	such element will exist as each one is distinct
	*/
	for(int i=0;i<n;i++) {
		for(int j=0;j<k;j++) {
			if(i == 0 || j == 0) V[i][j] = 1; 
			if(j > a[i]) continue;
			else {
				f=i-1;
				go = 0;
				while(f >= 0 && go == 0) {
					if(a[i] - a[f] == j) {
						V[i][j] = V[f][j] + 1;
						go=1;
					}
					f--;
				}
				if(go == 0) V[i][j] = V[i-1][j];
			}
		} 
	}
//	for(int i=0;i<n;i++) {
//		for(int j=0;j<k;j++) cout << V[i][j] << " ";
//		cout << "\n";
//	}
	int m=0;
	for(int j=0;j<k;j++) {
		m = max(m, V[n-1][j]);
	}
	return m;
}
