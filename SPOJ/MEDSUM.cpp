#include <bits/stdc++.h>
#define  MOD	1000000000

using namespace std;

const int MAX_N = 202;
const int MAX_L = 20002;
int A[MAX_N][MAX_L];
int n, L;

int median ( int i, int j ) {
	int a = 0, b = 0;
	for ( int k = 0; k < L - 1; ++k ) {
		if ( A[i][a] < A[j][b] ) ++a;
		else ++b;
	}
	return (A[i][a] < A[j][b] ? A[i][a] : A[j][b]);
}

int main ( ) {
	scanf("%d%d", &n, &L);
	for ( int i = 0; i < n; ++i )
		for ( int j = 0; j < L; ++j )
			scanf("%d", &A[i][j]);
	int sum = 0;
	for ( int i = 0; i < n; ++i )
		for ( int j = i + 1; j < n; ++j )
			sum = (sum + median(i, j)) % MOD;
	printf("%d\n", sum);
}
