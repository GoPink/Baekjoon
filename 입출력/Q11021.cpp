#include <iostream>

using namespace std;

int main(void) {
	int N = 0;
	int a = -1, b = -1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		cout << "Case #" <<i+1<<": "<< a + b << '\n';
	}
	return 0;
}