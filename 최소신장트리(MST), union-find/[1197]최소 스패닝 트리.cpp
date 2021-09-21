/*
그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.
최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.

첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다.
다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다.
C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.
그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고, 임의의 두 정점 사이에 경로가 있다.
최소 스패닝 트리의 가중치가 -2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다.

첫째 줄에 최소 스패닝 트리의 가중치를 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[10002];

struct lll {
	int a, b, val;
};

vector<lll> line;

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

bool Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return 0;
	parent[a] = b;
	return 1;
}
bool com(lll a, lll b) {
	return a.val < b.val;
}

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);

	int v, e;
	int ans = 0;
	cin >> v >> e;
	for (int i = 1; i <= v; i++)
		parent[i] = i;

	for (int i = 0; i < e; i++) {
		lll temp;
		cin >> temp.a >> temp.b >> temp.val;
		line.push_back(temp);
	}
	sort(line.begin(), line.end(), com);

	for (int i = 0; i < e; i++) {
		if (Union(line[i].a, line[i].b))
			ans += line[i].val;
	}

	cout << ans << endl;
}