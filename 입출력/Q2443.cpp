#include <iostream>
using namespace std;

int main(void) {
	int T = 0;
	scanf("%d", &T);
	for (int i = T-1; i >= 0; i--) {
		for (int j = 0; j < (T - i-1); j++) cout << " ";
		for (int j = 0; j < (2 * i + 1); j++) cout << "*";
		for (int j = 0; j < (T - i-1); j++) cout << " ";
		puts("");
	}
}