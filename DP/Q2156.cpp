#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int d[10001][2];

int main(void) {
	int num = 0;
	vector<int> v;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int tmp = 0;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	d[1][0] = 0;
	d[1][1] = v[0];
	d[2][0] = v[0];
	d[2][1] = v[0] + v[1];

	for (int i = 3; i <= num; i++) {
		d[i][0] = max(d[i - 1][1], d[i - 1][0]);
		d[i][1] = max(d[i - 2][1], d[i - 2][0] + v[i - 2]) + v[i - 1];
	}
	cout << max(d[num][0], d[num][1]) << endl;
}