#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d[100001][3];

int main(void) {
	int Test = 0, N = 0;
	vector<vector<int>> v;
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++) {
		scanf("%d", &N);
		vector<int> vt;
		v.push_back(vt);
		v.push_back(vt);

		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < N; k++) {
				int tmp = 0;
				scanf("%d", &tmp);
				v[j].push_back(tmp);
			}
		}
		d[1][0] = v[0][0]; //위 스티커
		d[1][1] = v[1][0]; //아래 스티커
		d[1][2] = 0;	   //안붙이기
		for (int i = 2; i <= N; i++) {
			d[i][0] = max(d[i - 1][1], d[i - 1][2]) + v[0][i-1];
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + v[1][i-1];
			d[i][2] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
		}
		printf("%d\n", max(d[N][0], max(d[N][1], d[N][2])));
		v.clear();
	}
}