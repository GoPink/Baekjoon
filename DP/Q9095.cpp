#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int d[12];
int main(void) {
	int T = 0;
	scanf("%d", &T);
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for (int i = 0; i < T; i++) {
		int tmp = 0;
		scanf("%d", &tmp);
		for (int i = 4; i <= tmp; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		cout << d[tmp] << endl;
	}
	return 0;
}