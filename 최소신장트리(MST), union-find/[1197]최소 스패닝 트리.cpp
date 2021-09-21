/*
�׷����� �־����� ��, �� �׷����� �ּ� ���д� Ʈ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
�ּ� ���д� Ʈ����, �־��� �׷����� ��� �������� �����ϴ� �κ� �׷��� �߿��� �� ����ġ�� ���� �ּ��� Ʈ���� ���Ѵ�.

ù° �ٿ� ������ ���� V(1 �� V �� 10,000)�� ������ ���� E(1 �� E �� 100,000)�� �־�����.
���� E���� �ٿ��� �� ������ ���� ������ ��Ÿ���� �� ���� A, B, C�� �־�����. �̴� A�� ������ B�� ������ ����ġ C�� �������� ����Ǿ� �ִٴ� �ǹ��̴�.
C�� ������ ���� ������, ������ 1,000,000�� ���� �ʴ´�.
�׷����� ������ 1������ V������ ��ȣ�� �Ű��� �ְ�, ������ �� ���� ���̿� ��ΰ� �ִ�.
�ּ� ���д� Ʈ���� ����ġ�� -2,147,483,648���� ũ�ų� ����, 2,147,483,647���� �۰ų� ���� �����͸� �Է����� �־�����.

ù° �ٿ� �ּ� ���д� Ʈ���� ����ġ�� ����Ѵ�.
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