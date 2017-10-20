#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int DFS(int d[],int start,deque<int> deq, vector<int> v[]);

int main(void) {
	int vertex = 0, edge = 0, result = 0;
	int d[1001];
	vector<int> v[1001];
	deque<int> deq;
	freopen("input.txt", "r", stdin);
	scanf("%d %d\n", &vertex, &edge);

	for (int i = 0; i < edge; i++) {
		int start = 0, end = 0;
		scanf("%d %d\n", &start, &end);
		v[start].push_back(end);
		v[end].push_back(start);
	}
	for (int i = 1; i <= vertex; i++) {
		if (d[i] == 0) {
			DFS(d, i, deq, v);
			result++;
		}
	}
	cout << result;
	return 0;
}

int DFS(int d[],int start, deque<int> deq,vector<int> v[]) {
	d[start] = 1;
	deq.push_back(start);

	//select
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (d[next] == 1) continue;
		else DFS(d, next, deq, v);
	}
	deq.pop_back();
	return 0;
}