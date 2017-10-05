#include <iostream>
using namespace std;

long long d[101][11];
int main(void) {
	int T = 0, sum = 0;
	scanf("%d", &T);
	d[1][0] = 0;
	for (int i = 1; i <= 9; i++) d[1][i] = 1;
	for (int i = 2; i <= T; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) d[i][j] = d[i - 1][1];
			else if (j == 9) d[i][j] = d[i - 1][8];
			else d[i][j] = (d[i - 1][j - 1] % 1000000000 + d[i - 1][j + 1] % 1000000000) % 1000000000;
		}
	}
	for (int i = 0; i < 10; i++) {
		sum = (sum % 1000000000 + d[T][i] % 1000000000) % 1000000000;
	}
	cout << sum;
	return 0;
}