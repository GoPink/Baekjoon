#include <iostream>
using namespace std;

long long d[1001][11];
int main(void) {
	int T = 0, sum = 0;
	scanf("%d", &T);
	for (int i = 0; i <= 9; i++) d[1][i] = 1;
	for (int i = 2; i <= T; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] = (d[i][j] % 10007 + d[i - 1][k] % 10007) % 10007;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		sum = (sum % 10007 + d[T][i] % 10007) % 10007;
	}
	cout << sum;
	return 0;
}