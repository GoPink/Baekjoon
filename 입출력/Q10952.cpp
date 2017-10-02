#include <iostream>

using namespace std;

int main(void) {
	int a = -1, b = -1;
	while (scanf("%d %d", &a, &b) ==2) {
		if (a == 0 && b == 0) return 0;
		cout << a + b << '\n';
	}
	return 0;
}