#include <iostream>
using namespace std;

char map[2500][2500];
void star(int size,int w, int h );

int main(void) {
	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < T; j++)
			map[i][j] = ' ';
	}
	star(T,0,0);
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < T; j++) {
			printf("%c", map[i][j]);
		}
		puts("");
	}
	return 0;
}

void star(int size,int w, int h) {
	if (size == 1) {
		map[w][h] = '*';
		return;
	}

	int next = size / 3;

	for (int i = 0,dx=w; i < 3; i++,dx+=next) {
		for (int j = 0,dy=h; j < 3; j++,dy+=next) {
			if (i == 1 && j == 1) continue;
			star(next,dx,dy);
		}
	}
}