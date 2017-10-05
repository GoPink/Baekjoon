#include <iostream>
using namespace std;

char map[8000][8000];

void star(int d, int x, int y);
int main(void) {
	int T = 0;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		for (int j = 1; j <= T * 2; j++)
			map[i][j] = ' ';
	}
	star(T, 1, T);
	for (int i = 1; i <= T; i++) {
		for (int j = 1; j <= T * 2; j++)
			printf("%c", map[i][j]);
		puts("");
	}
	return 0;
}

void star(int d, int x, int y) {
	if (d == 3) {
		map[x][y] = '*';

		map[x + 1][y - 1] = '*';
		map[x + 1][y + 1] = '*';

		map[x + 2][y - 2] = '*';
		map[x + 2][y - 1] = '*';
		map[x + 2][y] = '*';
		map[x + 2][y + 1] = '*';
		map[x + 2][y + 2] = '*';
		return;
	}
	star(d / 2, x, y);
	star(d / 2, x + (d / 2), y - (d / 2));
	star(d / 2, x + (d / 2), y + (d / 2));
}