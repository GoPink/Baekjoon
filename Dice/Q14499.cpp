#include <iostream>
using namespace std;

int map[21][21];
int DICE[5][4];

void Dice(int N, int M, int &x_pos, int &y_pos, int cmd);
int main(void) {
	int N = 0, M = 0, x = 0, y = 0, cmdNum = 0;
	int cmd = 0;
	scanf("%d %d %d %d %d\n", &N, &M, &x, &y, &cmdNum);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp = 0;
			scanf("%d", &tmp);
			map[i][j] = tmp;
		}
	}

	while (cmdNum--) {
		scanf("%d", &cmd);
		Dice(N, M, x, y, cmd);
	}
	return 0;
}
void Dice(int N, int M, int &x_pos, int &y_pos, int cmd) {
	int flag = 0;
	if (cmd == 1) {
		if ((y_pos + 1) >= M) flag = 1;
		else {
			y_pos++;
			swap(DICE[2][3], DICE[2][2]);
			swap(DICE[2][2], DICE[2][1]);
			swap(DICE[2][1], DICE[4][2]);
		}
	}
	else if (cmd == 2) {
		if ((y_pos - 1) < 0) flag = 1;
		else {
			y_pos--;
			swap(DICE[2][1], DICE[2][2]);
			swap(DICE[2][2], DICE[2][3]);
			swap(DICE[2][3], DICE[4][2]);
		}
	}
	else if (cmd == 3) {
		if ((x_pos - 1) < 0) flag = 1;
		else {
			x_pos--;
			swap(DICE[1][2], DICE[2][2]);
			swap(DICE[2][2], DICE[3][2]);
			swap(DICE[3][2], DICE[4][2]);
		}
	}
	else {
		if ((x_pos + 1) >= N) flag = 1;
		else {
			x_pos++;
			swap(DICE[4][2], DICE[3][2]);
			swap(DICE[3][2], DICE[2][2]);
			swap(DICE[2][2], DICE[1][2]);
		}
	}

	if (flag == 0) {
		if (map[x_pos][y_pos] == 0) map[x_pos][y_pos] = DICE[4][2];
		else {
			DICE[4][2] = map[x_pos][y_pos];
			map[x_pos][y_pos] = 0;
		}
		cout << DICE[2][2] << endl;
	}
}