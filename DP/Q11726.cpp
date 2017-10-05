#include <iostream>
#include <algorithm>

using namespace std;

int d[1001];
int main(void) {
	int T = 0;
	scanf("%d", &T);
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= T; i++) {
		d[i] = (d[i - 1] % 10007 + d[i - 2] % 10007) % 10007;
	}
	cout << d[T];
	return 0;
}