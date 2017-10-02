#include <iostream>

using namespace std;

int main(void) {
	int N = 0;
	int a = 0, b = 0;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		cout << a + b << '\n';
	}
}