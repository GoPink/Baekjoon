#include <iostream>
using namespace std;

int main(void) {
	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		for (int j = i+1; j < T; j++) cout << " ";
		for (int j = 0; j <= i; j++) cout << "*";
		puts("");
	}
	for (int i = 0; i < (T - 1); i++) {
		for (int j = 0; j <= i; j++) cout << " ";
		for (int j = i; j < (T-1); j++) cout << "*";
		puts("");
	}
}