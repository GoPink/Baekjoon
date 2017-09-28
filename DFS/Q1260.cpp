#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

void DFS(vector<int> ad[],int start,int vertex);
void BFS(vector<int> ad[],int start,int vertex);

deque<int> deq;
int visit[1001];
int cnt;

int main(void) {
	int vertex=0, edge=0, start=0, s=0, e=0;
	vector<int> ad[1001];	
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &vertex, &edge, &start);

	for (int i = 0; i < edge; i++) {
		scanf("%d %d\n", &s, &e);
		ad[s].push_back(e);
		ad[e].push_back(s);
	}

	for (int i = 1; i <= vertex; i++) {
		sort(ad[i].begin(), ad[i].end());
		auto last = unique(ad[i].begin(), ad[i].end());
		ad[i].erase(last, ad[i].end());
	}

	DFS(ad, start, vertex);
	cnt = 0;
	for (int i = 1; i <= vertex; i++) visit[i] = 0;
	deq.clear();
	puts("");
	BFS(ad, start, vertex);
	return 0;
}

void DFS(vector<int> ad[], int start,int vertex) {
	deq.push_back(start);
	visit[start] = 1;
	cnt++;
	cout << start << " ";
	if (cnt == vertex) return;
	

	for (int i = 0; i < ad[start].size(); i++) {
		if (visit[ad[start][i]] == 0) {
			DFS(ad, ad[start][i],vertex);
		}
	}
	deq.pop_back();
}

void BFS(vector<int> ad[], int start, int vertex) {
	if (count(deq.begin(), deq.end(), start) == 0)
		deq.push_back(start);

	visit[start] = 1;
	cnt++;
	cout << start << " ";
	if (cnt == vertex) return;
	for (int i = 0; i < ad[start].size(); i++) {
		if (visit[ad[start][i]] == 0) {
			deq.push_back(ad[start][i]);
			visit[ad[start][i]] = 1;
		}
	}
	deq.pop_front();
	BFS(ad, deq.front(), vertex);
}