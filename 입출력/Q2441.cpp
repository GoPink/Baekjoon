
#include <iostream>
using namespace std;

int main(void) {
	int T = 0;
	scanf("%d", &T);
	for (int i = T; i > 0; i--) {
		for (int j = i; j < T; j++) cout << " ";
		for (int j = i; j > 0; j--) cout << "*";
		puts("");
	}
}