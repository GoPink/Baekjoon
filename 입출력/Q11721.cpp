#include <iostream>
using namespace std;

int main(void) {
	char str[101];
	freopen("input.txt", "r", stdin);

	while (scanf("%10s", str) != -1) {
		printf("%s\n", str);
	}
}