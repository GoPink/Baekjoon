#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		for (int j = T-1; j > i; j--) cout << " ";
		for (int j = 0; j <= i; j++) cout << "*";
		puts("");
	}
}