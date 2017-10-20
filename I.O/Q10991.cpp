#include <iostream>
using namespace std;

int main(void) {
	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		for (int j = i+1; j < T; j++) cout << " ";
		for (int j = 0; j < 2 * i + 1; j++) {
				if (j % 2 == 0) cout << "*";
				else cout << " ";
		}
		puts("");
	}
}