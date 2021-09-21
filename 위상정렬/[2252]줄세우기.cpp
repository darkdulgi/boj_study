/*
N명의 학생들을 키 순서대로 줄을 세우려고 한다.
각 학생의 키를 직접 재서 정렬하면 간단하겠지만, 마땅한 방법이 없어서 두 학생의 키를 비교하는 방법을 사용하기로 하였다.
그나마도 모든 학생들을 다 비교해 본 것이 아니고, 일부 학생들의 키만을 비교해 보았다.
일부 학생들의 키를 비교한 결과가 주어졌을 때, 줄을 세우는 프로그램을 작성하시오.

첫째 줄에 N(1 ≤ N ≤ 32,000), M(1 ≤ M ≤ 100,000)이 주어진다. M은 키를 비교한 회수이다. 다음 M개의 줄에는 키를 비교한 두 학생의 번호 A, B가 주어진다.
이는 학생 A가 학생 B의 앞에 서야 한다는 의미이다.
학생들의 번호는 1번부터 N번이다.

첫째 줄에 학생들을 키 순서대로 줄을 세운 결과를 출력한다. 답이 여러 가지인 경우에는 아무거나 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_NUM 3200

using namespace std;

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);
	int n, m;
	queue<int> q;				//위상 정렬을 위한 큐.
	vector<int> man[MAX_NUM];	//키를 비교하는 순서를 담는 벡터 배열. 인덱스는 학생 번호이며 데이터는 자신보다 큰(자신이 가리키는) 학생의 번호.
	vector<int> ans;			//정답인 키 순서
	int size[MAX_NUM] = { 0 };	//자기가 몇 명보다 큰 지를 담는 배열.(자신을 가리키는 학생 수) 

	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		man[a].push_back(b);
		size[b]++;
	}

	for (int i = 1; i <= n; i++) {	//진입 차수가 0인 노드를 큐에 담고 탐색 후 -1로 저장.
		if (size[i] == 0) {
			q.push(i);
			size[i] = -1;
		}
	}

	while (!q.empty()) {	//위상 정렬
		int temp = q.front();
		for (int j = 0; j < man[temp].size(); j++) {	//큐 맨앞의 노드의 간선 제거. 하는 김에 진입 차수가 0이 되는 노드 탐색 후 큐 삽입.
			size[man[temp][j]]--;
			if (size[man[temp][j]] == 0)
				q.push(man[temp][j]);
		}
		man[temp].clear();
		ans.push_back(temp);
		size[temp] = -1;
		q.pop();	//큐 맨앞 원소 빼기
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
}