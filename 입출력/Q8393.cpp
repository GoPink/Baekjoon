#include <iostream>
using namespace std;

int main(void) {
	int T = 0,sum=0;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
		sum += i;
	cout << sum;
}