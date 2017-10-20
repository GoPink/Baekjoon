#include <iostream>
using namespace std;

int main(void) {
	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < i; j++) cout << " ";
		for (int j = 0; j < 2 * (T - i)-1; j++) cout << "*";
		puts("");
	}
	for (int i = T - 1; i > 0; i-- ){
		for (int j = 0; j < i-1; j++) cout << " ";
		for (int j = 0; j < 2*(T-i)+1; j++) cout << "*";
		puts("");
	}
	return 0;
}