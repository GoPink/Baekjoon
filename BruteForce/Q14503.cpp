#include <iostream>
using namespace std;

void mapclear(int (*map)[51], int &x_pos, int &y_pos, int &dir, int &result);

int main(void) {
	int map[51][51];
	int N = 0, M = 0;
	int dir = 0, x_pos = 0, y_pos = 0;
	int result = 0;
	scanf("%d %d\n", &N, &M);
	scanf("%d %d %d\n", &x_pos, &y_pos, &dir);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int tmp = 0;
			scanf("%d", &tmp);
			map[i][j] = tmp;
		}
	}
	mapclear(map, ++x_pos, ++y_pos, dir, result);
	cout << result;
	return 0;
}
void mapclear(int(*map)[51], int &x_pos, int &y_pos, int &dir, int &result) {
	if(map[x_pos][y_pos]==0) {
		map[x_pos][y_pos] = 2;
		result++;
	}
	int flag = 0;

	while (flag != 4) {
		//ºÏ
		if (dir == 0) {
			dir = 3;
			if (map[x_pos][y_pos - 1] == 0) {
				y_pos -= 1;
				break;
			}
			
		}
		//µ¿
		else if (dir == 1) {
			dir = 0;
			if (map[x_pos - 1][y_pos] == 0) {
				x_pos -= 1;
				break;
			}
			
		}

		//³²
		else if (dir == 2) {
			dir = 1;
			if (map[x_pos][y_pos + 1] == 0) {
				y_pos += 1;
				break;
			}
			
		}
		//¼­
		else {
			dir = 2;
			if (map[x_pos + 1][y_pos] == 0) {
				x_pos += 1;
				break;
			}
		}
		flag++;
	}
	if (flag != 4) {
		mapclear(map, x_pos, y_pos, dir, result);
		return;
	}

	if (flag == 4) {
		if (dir == 0) {
			if (map[x_pos + 1][y_pos] != 1) {
				x_pos += 1;
			}
			else return;
		}
		else if (dir == 1) {
			if (map[x_pos][y_pos - 1] != 1) {
				y_pos -= 1;
			}
			else return;
		}
		else if (dir == 2) {
			if (map[x_pos - 1][y_pos] != 1) {
				x_pos -= 1;
			}
			else return;
		}
		else {
			if (map[x_pos][y_pos + 1] != 1) {
				y_pos += 1;
			}
			else return;
		}
		mapclear(map, x_pos, y_pos, dir, result);
	}
}