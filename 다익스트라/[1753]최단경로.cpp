/*
����׷����� �־����� �־��� ���������� �ٸ� ��� ���������� �ִ� ��θ� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
��, ��� ������ ����ġ�� 10 ������ �ڿ����̴�.

ù° �ٿ� ������ ���� V�� ������ ���� E�� �־�����. (1 �� V �� 20,000, 1 �� E �� 300,000) ��� �������� 1���� V���� ��ȣ�� �Ű��� �ִٰ� �����Ѵ�.
��° �ٿ��� ���� ������ ��ȣ K(1 �� K �� V)�� �־�����.
��° �ٺ��� E���� �ٿ� ���� �� ������ ��Ÿ���� �� ���� ���� (u, v, w)�� ������� �־�����.
�̴� u���� v�� ���� ����ġ w�� ������ �����Ѵٴ� ���̴�. u�� v�� ���� �ٸ��� w�� 10 ������ �ڿ����̴�. ���� �ٸ� �� ���� ���̿� ���� ���� ������ ������ ���� ������ �����Ѵ�.

ù° �ٺ��� V���� �ٿ� ����, i��° �ٿ� i�� ���������� �ִ� ����� ��ΰ��� ����Ѵ�.
������ �ڽ��� 0���� ����ϰ�, ��ΰ� �������� �ʴ� ��쿡�� INF�� ����ϸ� �ȴ�.
*/

#include <iostream>
#include <deque>
#include <queue>	//���ͽ�Ʈ��� ���� �ð����⵵�� ���� �켱���� ť�� ��� �� ��ŭ�� �迭�� �ʿ��ϴ�.

using namespace std;

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int v, e, start;
	int di[20001];	// ���������� �� ��������� �ּ� ����� ����
	for (int i = 0; i < 20001; i++) di[i] = 2100000000;
	deque<pair<int, int>> graph[20001];		// �׷��� ������ ���� ���� ����Ʈ
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	//����� ���� ������� ť���� ���������� ������ �켱���� ������.
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
		if (di[node] > value) di[node] = value;		// �ּ� ����� ������ ���� ������ �� �迭 di�� �ִ´�. �ƴ� �� �����Ѵ�.
		else continue;
		for (int i = 0; i < graph[node].size(); i++)
			pq.push(make_pair(value + graph[node][i].first, graph[node][i].second));	// ����� ������ �տ��� �����ϰ� ���� �� ������ ��� �ִ´�.
	}
	for (int i = 1; i <= v; i++) {
		if (di[i] == 2100000000) cout << "INF" << '\n';
		else cout << di[i] << '\n';
	}
}