#include <iostream>
using namespace std;

void tromino(int N, int M, int(*map)[501], int &result);
int main(void) {
	int N = 0, M = 0;
	int map[501][501];
	int result = 0;
	scanf("%d %d\n", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int tmp = 0;
			scanf("%d", &tmp);
			map[i][j] = tmp;
		}
	}
	tromino(N, M, map, result);
	cout << result << endl;
	return 0;
}

void tromino(int N, int M, int(*map)[501], int &result) {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= (M - 4 + 1); j++) {
			int tmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
			if (tmp > result) result = tmp;
		}
	}
	for (int i = 1; i <= (N - 4 + 1); i++) {
		for (int j = 1; j <= M; j++) {
			int tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
			if (tmp > result) result = tmp;
		}
	}

	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 1; j++) {
			int tmp = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1];
			if (tmp > result) result = tmp;
		}
	}
	
	for (int i = 1; i <= (N - 3 + 1); i++) {
		for (int j = 1; j <= M - 1; j++) {
			int tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
			if (tmp > result) result = tmp;
		}
	}	
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= (M - 3 + 1); j++) {
			int tmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 2];
			if (tmp > result) result = tmp;
		}
	}	
	for (int i = 1; i <= (N - 3 + 1); i++) {
		for (int j = 1; j <= M - 1; j++) {
			int tmp = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
			if (tmp > result) result = tmp;
		}
	}	
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= (M - 3 + 1); j++) {
			int tmp = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i][j + 2];
			if (tmp > result) result = tmp;
		}
	}
	
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 2; j <= M - 1; j++) {
			int tmp = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 1][j + 1];
			if (tmp > result) result = tmp;
		}
	}	
	for (int i = 1; i <= (N - 3 + 1); i++) {
		for (int j = 2; j <= M; j++) {
			int tmp = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 2][j];
			if (tmp > result) result = tmp;
		}
	}
	
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= (M - 3 + 1); j++) {
			int tmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
			if (tmp > result) result = tmp;
		}
	}	
	for (int i = 1; i <= (N - 3 + 1); i++) {
		for (int j = 1; j <= M - 1; j++) {
			int tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
			if (tmp > result) result = tmp;
		}
	}	
	for (int i = 1; i <= (N - 3 + 1); i++) {
		for (int j = 1; j <= M - 1; j++) {
			int tmp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
			if (tmp > result) result = tmp;
		}
	}
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 2; j <= (M - 1); j++) {
			int tmp = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j - 1];
			if (tmp > result) result = tmp;
		}
	}

	
	for (int i = 1; i <= (N - 3 + 1); i++) {
		for (int j = 2; j <= M; j++) {
			int tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j - 1];
			if (tmp > result) result = tmp;
		}
	}
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= (M - 3 + 1); j++) {
			int tmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];
			if (tmp > result) result = tmp;
		}
	}
	for (int i = 1; i <= (N - 3 + 1); i++) {
		for (int j = 1; j <= M - 1; j++) {
			int tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j + 1];
			if (tmp > result) result = tmp;
		}
	}
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= (M - 3 + 1); j++) {
			int tmp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
			if (tmp > result) result = tmp;
		}
	}

	
	for (int i = 1; i <= (N - 3 + 1); i++) {
		for (int j = 2; j <= M ; j++) {
			int tmp = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 2][j - 1];
			if (tmp > result) result = tmp;
		}
	}
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= (M - 3 + 1); j++) {
			int tmp = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
			if (tmp > result) result = tmp;
		}
	}
}