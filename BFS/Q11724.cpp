#include <iostream>
#include <vector>
#include <deque>

using namespace std;
int BFS(int d[],int start,deque<int> deq, vector<int> v[]);

int main(void) {
	int vertex = 0, edge = 0, result = 0;
	int d[1001];
	vector<int> v[1001];
	deque<int> deq;
	scanf("%d %d\n", &vertex, &edge);

	for (int i = 0; i < edge; i++) {
		int start = 0, end = 0;
		scanf("%d %d\n", &start, &end);
		v[start].push_back(end);
		v[end].push_back(start);
	}
	for (int i = 1; i <= vertex; i++) {
		if (d[i] == 0) {
			BFS(d, i, deq, v);
			result++;
		}
	}
	cout << result;
	return 0;
}

int BFS(int d[],int start, deque<int> deq, vector<int> v[]) {
	d[start] = 1;
	//push

	for (int i = 0; i < v[start].size(); i++) {
		if (d[v[start][i]] == 0) {
			int flag = 0;
			for (int j = 0; j < deq.size(); j++) {
				int tmp = deq[j];
				if (tmp == v[start][i]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) deq.push_back(v[start][i]);
		}
	}

	//pop
	int next = 0;
	if (deq.size() != 0) {
		next = deq[0];
		deq.pop_front();
		BFS(d, next, deq, v);
	}
	else return 0;
	return 0;
}