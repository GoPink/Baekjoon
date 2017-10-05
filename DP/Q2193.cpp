#include <iostream>
using namespace std;

long long d[91][3];

int main(void) {
	int T = 0, sum = 0;
	scanf("%d", &T);
	d[1][0] = 0;
	d[1][1] = 1;
	for (int i = 2; i <= T; i++) {
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}
	cout << d[T][0] + d[T][1];
	return 0;
}