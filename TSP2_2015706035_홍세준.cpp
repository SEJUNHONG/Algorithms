#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <climits>
#include <time.h>
using namespace std;

#define N 5
#define INF INT_MAX

struct Node{
	vector<pair<int, int>> path;
	int WMatrix[N][N];
	int bound;
	int vertex;
	int level;
};

Node* newNode(int Parent[N][N], vector<pair<int, int>> const &path, int level, int i, int j){
	Node* node = new Node;
	node->path = path;
	if (level != 0)
		node->path.push_back(make_pair(i, j));
	memcpy(node->WMatrix, Parent, sizeof node->WMatrix);
	for (int k = 0; level != 0 && k < N; k++){
		node->WMatrix[i][k] = INF;
		node->WMatrix[k][j] = INF;
	}
	node->WMatrix[j][0] = INF;
	node->level = level;
	node->vertex = j;
	return node;
}

void Row(int WMatrix[N][N], int row[N]){
	fill_n(row, N, INF);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (WMatrix[i][j] < row[i])
				row[i] = WMatrix[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (WMatrix[i][j] != INF && row[i] != INF)
				WMatrix[i][j] -= row[i];
}

void Column(int WMatrix[N][N], int col[N]){
	fill_n(col, N, INF);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (WMatrix[i][j] < col[j])
				col[j] = WMatrix[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (WMatrix[i][j] != INF && col[j] != INF)
				WMatrix[i][j] -= col[j];
}

int Bound(int WMatrix[N][N]){
	clock_t begin2, end2;
	begin2 = clock();
	int cost = 0;
	int row[N];
	Row(WMatrix, row);
	int col[N];
	Column(WMatrix, col);
	for (int i = 0; i < N; i++)
		cost += (row[i] != INF) ? row[i] : 0, cost += (col[i] != INF) ? col[i] : 0;
	end2 = clock();
	//cout << "Bound 함수를 실행하는데 걸리는 시간: " << (end2 - begin2) << endl;
	return cost;
}

void print(vector<pair<int, int>> const &list, int cnt){
	for (int i = 0; i < list.size(); i++)
		cout << list[i].first + 1 << " -> " << list[i].second + 1 << endl;
	cout << "노드의 수: " << cnt << endl;
}

struct comp {
	bool operator()(const Node* lhs, const Node* rhs) const{
		return lhs->bound > rhs->bound;
	}
};

int travel2(int W[N][N], int cnt){
	priority_queue<Node*, std::vector<Node*>, comp> PQ;
	vector<pair<int, int>> v;
	Node* root = newNode(W, v, 0, -1, 0);
	root->bound = Bound(root->WMatrix);
	PQ.push(root);
	while (!PQ.empty()){
		Node* min = PQ.top();
		PQ.pop();
		int i = min->vertex;
		if (min->level == N - 1){
			min->path.push_back(make_pair(i, 0));
			print(min->path, cnt);
			return min->bound;
		}
		for (int j = 0; j < N; j++){
			if (min->WMatrix[i][j] != INF){
				Node* child = newNode(min->WMatrix, min->path, min->level + 1, i, j);
				cnt++;
				child->bound = min->bound + min->WMatrix[i][j] + Bound(child->WMatrix);
				PQ.push(child);
			}
		}
		delete min;
	}
}

int main(){
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
	cout << "Best First Search Branch and Bound Traveling Salesman Problem의 최적의 해: " << travel2(W, cnt)<<"\n";
	end1 = clock();
	cout << "최적의 솔루션을 찾는데 걸리는 시간: " << (end1 - begin1) << endl;
	system("pause");
	return 0;
}