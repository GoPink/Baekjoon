#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

#define MAX_SIZE 25

int map[MAX_SIZE][MAX_SIZE] = { 0 };
int memo[MAX_SIZE][MAX_SIZE] = { 0 };
int COUNT;
int map_size;

int counting(int i, int j);

int main(void) {
	vector<int> result;

	freopen("input.txt", "r", stdin);

	scanf("%d\n", &map_size);
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++)
			scanf("%1d", &map[i][j]);
	}

	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			if (map[i][j] == 1 && memo[i][j] == 0) {
				result.push_back(counting(i, j));
				COUNT = 0;
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for (int &x : result)
		cout << x << endl;

	return 0;
}

int counting(int i, int j) {
	memo[i][j] = 1;
	COUNT++;
	if(j+1 < map_size && map[i][j+1]==1 && memo[i][j+1]==0)
		counting(i, j+1);
	if(i+1 < map_size && map[i+1][j]==1 && memo[i+1][j]==0)
		counting(i + 1, j);
	if (j - 1 >= 0 && map[i][j-1] == 1 && memo[i][j-1] == 0)
		counting(i, j - 1);
	if (i - 1 >= 0 && map[i - 1][j] == 1 && memo[i - 1][j] == 0)
		counting(i - 1, j);
	return COUNT;
}