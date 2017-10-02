#include <iostream>
using namespace std;

int main(void) {
	int T = 0, num = 0, result = 0;
	scanf("%d\n", &T);
	for (int i = 0; i < T; i++) {
		scanf("%1d", &num);
		result += num;
	}
	cout << result;
}