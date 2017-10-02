#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v;
	int T = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int tmp = 0;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	auto p = min_element(v.begin(), v.end());
	cout << *p << " ";
	p = max_element(v.begin(), v.end());
	cout << *p;

}