#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <climits>
#include <time.h>
#include <utility>
using namespace std;
#define N 5
#define INF	 INT_MAX

struct Node {
	int level;
	int bound;
	vector<int> path[N+1];
};

bool find_path(Node v, int i) {
	find(v.path[N + 1].begin(), v.path[N + 1].end(), i) != v.path[N + 1].end();
}

bool Promising(Node v, int minLength) {
	if (v.bound < minLength)
		return true;
}

int length(Node u, int W[N][N]) {
	int i, j;
	int len = 0;
	for (int k = 0; k < N ; k++) {
		i = u.path[k].front();
		j = u.path[k + 1].front();
		len += W[i][j];
	}
	return len;
}

int bound(Node v, int minLength, int W[N][N]) {
	clock_t begin2, end2;
	begin2 = clock();
	priority_queue<int> pq;
	queue<int> q;
	int i, j, k;
	int min;
	int Length = 0;
	q.push(v.path[0].front());
	pq.push(v.path[0].front());
	for (k = 1; k < N; k++) {
		if (!v.path[k].front()) {
			for (i = N - 1; i = 0; i--) {
				if (i == pq.top())
					pq.pop();
				else {
					pq.pop();
					for (j = 0; j < N; j++) {
						if (W[i][j] < min)
							min = W[i][j];
					}
				}
			}
		}
		else {
			j = v.path[k].front();
			pq.push(j);
			q.push(j);
			min = W[q.front()][j];
			q.pop();
		}
		Length += min;
	}
	end2 = clock();
	cout << "Bound 함수를 실행하는데 걸리는 시간: " << (end2 - begin2) << endl;
	return Length;
}

void print(Node u, int cnt) {
	int j = u.path[0].front();
	int k;
	for (int i = 1; i < N+1; i++) {
		k = u.path[i].front();
		cout << j << " -> " << k << endl;
		j = u.path[i].front();;
	}
	cout << "노드의 수: " << cnt << endl;
}

int travel(int n, int W[N][N], int cnt) {
	priority_queue<Node> PQ;
	Node u, v;
	int minLength;
	PQ.empty();
	v.level = 0;
	v.path[N + 1] = {1};
	minLength = INF;
	v.bound = bound(v, minLength, W);
	PQ.push(v);
	while (!PQ.empty()) {
		v = PQ.top();
		PQ.pop();
		if (Promising(v, minLength)) {
			u.level = v.level + 1;
			cnt++;
			for (int i = 2; i < n + 1; i++) {
				if (!find_path(v, i)) {
					u.path[N + 1] = v.path[N + 1];
					u.path[N + 1].push_back(i);
					if (u.level == n - 2) {
						print(u, cnt);
						for (int j = 1; j < N; j++)
							if (!find_path(u, j))
								u.path[N + 1].push_back(j);
						u.path[N + 1].push_back(1);
						if (length(u, W) < minLength){
							minLength = length(u, W);
						}
					}
					else {
						u.bound = bound(u, minLength, W);
						if (u.bound < minLength)
							PQ.push(u);
					}
				}
			}
		}
	}
}

int main() {
	Node* node = new Node;
	clock_t begin1, end1;
	begin1 = clock();
	int cnt = 1;
	/*int W[N][N] = {{ INF, 14,  4,   10,   20 },
		{ 14,  INF, 7,  8,   7 },
		{ 4,   5,  INF, 7,   16 },
		{ 11,   7,   9,   INF, 2 },
		{ 18,   7,   17,   4,   INF }
	};
	int W[N][N] = { { INF, 1,  INF,   1,   5 },
		{ 9,  INF, 3,  2,   INF },
		{ INF,   INF,  INF, 4,   INF },
		{ INF,   INF,   2,   INF, 3 },
		{ 3,   INF,   INF,   INF,   INF }
	};*/
	int W[N][N] = { { INF, 3,  3,   3,   3 },
		{ 3,  INF, 3, 3,  3    },
		{ 3,   3,  INF, 3,   3 },
		{ 3,   3,   3,   INF, 3 },
		{ 3,   3,   3,   3,   INF }
	};
	cout << "Best First Search Branch and Bound Traveling Salesman Problem의 최적의 해는 " << travel(N, W, cnt) << "\n";
	end1 = clock();
	cout << "최적의 솔루션을 찾는데 걸리는 시간: " << (end1 - begin1) << endl;
	system("pause");
	return 0;
}