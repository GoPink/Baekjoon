#include <iostream>
#include <algorithm>

using namespace std;

int d[1000001];
int main(void) {
	int T = 0;
	scanf("%d", &T);
	d[1] = 0;
	d[2] = 1;
	d[3] = 1;
	for (int i = 4; i <= T; i++) {
		if (i % 6 == 0) d[i] = min(d[i - 1], min(d[i / 3], d[i / 2])) + 1;
		else if (i % 3 == 0) d[i] = min(d[i - 1], d[i / 3]) + 1;
		else if (i % 2 == 0) d[i] = min(d[i - 1], d[i / 2]) + 1;
		else d[i] = d[i - 1] + 1;
	}
	cout << d[T];
	return 0;
}