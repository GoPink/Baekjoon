#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<int> score;
	vector<int> result;
	int numOfStairs;
	int tmp = 0;

	//freopen("input.txt", "r", stdin);
	scanf("%d", &numOfStairs);

	score.push_back(0);
	for (int i = 0; i < numOfStairs; i++) {
		scanf("%d", &tmp);
		score.push_back(tmp);
	}

	result.push_back(0);
	result.push_back(score[1]);
	result.push_back(score[1]+score[2]);
	for (int i = 3; i <= numOfStairs; i++) {
		tmp = max(result[i - 2] + score[i], result[i - 3] + score[i - 1] + score[i]);
		result.push_back(tmp);
	}
	cout << result.back() << '\n';
	return 0;
}