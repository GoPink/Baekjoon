#include <iostream>
using namespace std;

int main(void) {
	int T = 0;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		for (int j = 0; j < (T - 1 - i); j++) cout << " ";
		for (int j = 0; j < 2 * i + 1; j++) cout << "*";
		puts("");
	}
}