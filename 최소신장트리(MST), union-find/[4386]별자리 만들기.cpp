/*
�����̴� ������ ���̴�. ���� �����̴� �ƹ����Գ� �κ귯�� �ִ� n���� ������ �̾ ���ڸ��� �ϳ� ���� ���̴�. ���ڸ��� ������ ������ ����.
���ڸ��� �̷�� ���� ���� �ٸ� �� ���� ���������� ���� �����̴�.
��� ������ ���ڸ� ���� ���� ���� ���� ��/���������� �̾��� �־�� �Ѵ�.
������ 2���� ��� ���� ���� �ִ�. ���� �ϳ� ���� ������ �� �� ������ �Ÿ���ŭ�� ����� ��ٰ� �� ��, ���ڸ��� ����� �ּ� ����� ���Ͻÿ�.

ù° �ٿ� ���� ���� n�� �־�����. (1 �� n �� 100)
��° �ٺ��� n���� �ٿ� ���� �� ���� x, y��ǥ�� �Ǽ� ���·� �־�����, �ִ� �Ҽ��� ��°�ڸ����� �־�����. ��ǥ�� 1000�� ���� �ʴ� ���� �Ǽ��̴�.

ù° �ٿ� ������ ����Ѵ�. ����/��� ������ 10-2���� ����Ѵ�.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int parent[1000];

struct lll {
	int a, b;
	float val;
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
	float ans = 0;
	cin >> v;
	vector<pair<float, float>> star(v + 1);
	e = v * (v - 1) / 2;
	for (int i = 1; i <= v; i++)
		parent[i] = i;

	for (int i = 1; i <= v; i++)
		cin >> star[i].first >> star[i].second;

	for (int i = 1; i < v; i++) {
		for (int j = i + 1; j <= v; j++) {
			lll temp;
			temp.a = i;
			temp.b = j;
			temp.val = sqrt((star[i].first - star[j].first) * (star[i].first - star[j].first) + (star[i].second - star[j].second) * (star[i].second - star[j].second));
			line.push_back(temp);
		}

	}
	sort(line.begin(), line.end(), com);

	for (int i = 0; i < e; i++) {
		if (Union(line[i].a, line[i].b)) {
			ans += line[i].val;

		}
	}

	printf("%.2f", ans);
}