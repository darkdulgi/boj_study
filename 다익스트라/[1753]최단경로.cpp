/*
방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오.
단, 모든 간선의 가중치는 10 이하의 자연수이다.

첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. (1 ≤ V ≤ 20,000, 1 ≤ E ≤ 300,000) 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다.
둘째 줄에는 시작 정점의 번호 K(1 ≤ K ≤ V)가 주어진다.
셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 (u, v, w)가 순서대로 주어진다.
이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다. u와 v는 서로 다르며 w는 10 이하의 자연수이다. 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.

첫째 줄부터 V개의 줄에 걸쳐, i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다.
시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.
*/

#include <iostream>
#include <deque>
#include <queue>	//다익스트라는 좋은 시간복잡도를 위해 우선순위 큐와 노드 수 만큼의 배열이 필요하다.

using namespace std;

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int v, e, start;
	int di[20001];	// 시작점부터 각 노드들까지의 최소 비용을 저장
	for (int i = 0; i < 20001; i++) di[i] = 2100000000;
	deque<pair<int, int>> graph[20001];		// 그래프 구현을 위한 인접 리스트
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	//비용이 작은 순서대로 큐에서 빠져나오기 때문에 우선순위 재지정.
	cin >> v >> e;
	cin >> start;
	di[start] = 0;
	while (e--) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(c, b));
		if (a == start) pq.push(make_pair(c, b));
	}
	while (!pq.empty()) {
		int node = pq.top().second;
		int value = pq.top().first;
		pq.pop();
		if (di[node] > value) di[node] = value;		// 최소 비용을 가지는 쌍이 들어왔을 시 배열 di에 넣는다. 아닐 시 무시한다.
		else continue;
		for (int i = 0; i < graph[node].size(); i++)
			pq.push(make_pair(value + graph[node][i].first, graph[node][i].second));	// 비용이 높더라도 앞에서 무시하고 버릴 수 때문에 모두 넣는다.
	}
	for (int i = 1; i <= v; i++) {
		if (di[i] == 2100000000) cout << "INF" << '\n';
		else cout << di[i] << '\n';
	}
}