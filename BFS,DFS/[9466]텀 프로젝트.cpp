/*이번 가을학기에 '문제 해결' 강의를 신청한 학생들은 텀 프로젝트를 수행해야 한다. 프로젝트 팀원 수에는 제한이 없다.
심지어 모든 학생들이 동일한 팀의 팀원인 경우와 같이 한 팀만 있을 수도 있다.
프로젝트 팀을 구성하기 위해, 모든 학생들은 프로젝트를 함께하고 싶은 학생을 선택해야 한다. (단, 단 한 명만 선택할 수 있다.)
혼자 하고 싶어하는 학생은 자기 자신을 선택하는 것도 가능하다.
학생들이(s1, s2, ..., sr)이라 할 때, r=1이고 s1이 s1을 선택하는 경우나, s1이 s2를 선택하고, s2가 s3를 선택하고,..., sr-1이 sr을 선택하고, sr이 s1을 선택하는 경우에만 한 팀이 될 수 있다.
주어진 선택의 결과를 보고 어느 프로젝트 팀에도 속하지 않는 학생들의 수를 계산하는 프로그램을 작성하라.

첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스의 첫 줄에는 학생의 수가 정수 n (2 ≤ n ≤ 100,000)으로 주어진다.
각 테스트 케이스의 둘째 줄에는 선택된 학생들의 번호가 주어진다. (모든 학생들은 1부터 n까지 번호가 부여된다.)

각 테스트 케이스마다 한 줄에 출력하고, 각 줄에는 프로젝트 팀에 속하지 못한 학생들의 수를 나타내면 된다.
*/
#include <iostream>
#include <queue>
#define MEM 100001
using namespace std;

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		int arr[MEM];
		int want[MEM] = { 0 };
		int team[MEM] = { 0 };
		int teamnum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			want[arr[i]]++;
		}

		for (int i = 1; i <= n; i++) {
			if (i == arr[i] && team[i] == 0) {	//향하는 간선이 아무도 없는 노드부터 DFS시작. 중간에 사이클 만날 때까지 진행. DFS안쓰면 시간초과난다.
				team[i] = 1;
				teamnum++;
				continue;
			}
			if (want[i] == 0) {
				bool come[MEM] = { 0 };
				bool cycle = 0;
				int cyclefirst;
				int here = i;
				while (1) {
					come[here] = 1;
					here = arr[here];
					if (cycle == 1 && here == cyclefirst) break;	//사이클이 이루어지면 사이클 노드들의 기록을 위해 한번 더 돌리고 루프를 끝낸다.
					if (cycle == 0 && come[here] == 1) {
						cycle = 1;
						cyclefirst = here;
					}
					if (cycle == 0 && (team[here] == 1 || team[here] == -1)) break;
					if (cycle) {
						team[here] = 1;
						teamnum++;
					}
					else team[here] = -1;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			if (team[i] == 0 && want[i] == 1) {	//노드가 2개 이상이고 서로를 향하는 간선이 모두 1개인 고립된 사이클에 대한 계산
				int here = i;
				int first = i;
				while (1) {
					team[here] = 1;
					teamnum++;
					here = arr[here];
					if (here == first) break;
				}
			}
		}

		cout << n - teamnum << '\n';
	}
}