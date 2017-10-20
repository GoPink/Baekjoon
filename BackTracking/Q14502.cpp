#include <iostream>
using namespace std;
int d[10][10];
void Go(int(*map)[10], int(*d)[10],int &count, int N, int M,int &result);
void Virus(int(*map)[10], int N, int M,int x_pos, int y_pos, int(*d)[10]);
int main(void) {
	int N = 0, M = 0;
	int map[10][10];
	int count = 0;
	int result = 0;
	scanf("%d %d\n", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int tmp = 0;
			scanf("%d", &tmp);
			map[i][j] = tmp;
		}
	}
	Go(map, d, count, N, M, result);
	cout << result;
	return 0;
}

void Go(int(*map)[10], int(*d)[10], int &count, int N, int M, int &result) {
	//벽세울 위치 찾기
	if (count != 3) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (map[i][j] == 0) {
					count++;
					map[i][j] = 1;
					Go(map, d,count, N, M,result);
					map[i][j] = 0;
					count--;
				}
			}
		}
	}
	if (count != 3) return;

	int copy[10][10];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			copy[i][j] = map[i][j];
		}
	}

	// 바이러스 확산시키기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if(copy[i][j]==2) Virus(copy, N, M, i, j, d);
		}
	}

	// 빈칸 세기
	int tmp = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (copy[i][j] == 0) tmp++;
		}
	}

	if (tmp > result) result = tmp;
	//방문 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			d[i][j] = 0;
		}
	}
}

void Virus(int(*map)[10], int N, int M, int x_pos, int y_pos, int(*d)[10]) {
	if (d[x_pos][y_pos] == 0) {
		d[x_pos][y_pos] = 1;
		if ((x_pos - 1) >= 1 && map[x_pos - 1][y_pos] != 1) {
			map[x_pos - 1][y_pos] = 2;
			Virus(map, N, M, x_pos - 1, y_pos, d);
		}
		if ((x_pos + 1) <= N && map[x_pos + 1][y_pos] != 1) {
			map[x_pos + 1][y_pos] = 2;
			Virus(map, N, M, x_pos + 1, y_pos, d);
		}
		if ((y_pos - 1) >= 1 && map[x_pos][y_pos - 1] != 1) {
			map[x_pos][y_pos - 1] = 2;
			Virus(map, N, M, x_pos, y_pos - 1, d);
		}
		if ((y_pos + 1) <= M && map[x_pos][y_pos + 1] != 1) {
			map[x_pos][y_pos + 1] = 2;
			Virus(map, N, M, x_pos, y_pos + 1, d);
		}
	}
}