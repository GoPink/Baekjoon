#include <iostream>
using namespace std;

int main(void) {
	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		for (int j = i + 1; j < T; j++) cout << " ";
		for (int j = 0; j < 2 * i + 1; j++) {
			if (i >= 1 && i<(T-1)) {
				if (j == 0 || j == 2 * i) cout << "*";
				else cout << " ";
			}
			else cout << "*";
		}
		puts("");
	}
}