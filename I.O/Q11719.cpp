#include <iostream>
#include <string>

using namespace std;
int main(void) {
	char c = 0;
	while ((c = getchar()) != EOF)
		putchar(c);
	return 0;
}