/*�̹� �����б⿡ '���� �ذ�' ���Ǹ� ��û�� �л����� �� ������Ʈ�� �����ؾ� �Ѵ�. ������Ʈ ���� ������ ������ ����.
������ ��� �л����� ������ ���� ������ ���� ���� �� ���� ���� ���� �ִ�.
������Ʈ ���� �����ϱ� ����, ��� �л����� ������Ʈ�� �Բ��ϰ� ���� �л��� �����ؾ� �Ѵ�. (��, �� �� �� ������ �� �ִ�.)
ȥ�� �ϰ� �;��ϴ� �л��� �ڱ� �ڽ��� �����ϴ� �͵� �����ϴ�.
�л�����(s1, s2, ..., sr)�̶� �� ��, r=1�̰� s1�� s1�� �����ϴ� ��쳪, s1�� s2�� �����ϰ�, s2�� s3�� �����ϰ�,..., sr-1�� sr�� �����ϰ�, sr�� s1�� �����ϴ� ��쿡�� �� ���� �� �� �ִ�.
�־��� ������ ����� ���� ��� ������Ʈ ������ ������ �ʴ� �л����� ���� ����ϴ� ���α׷��� �ۼ��϶�.

ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� ù �ٿ��� �л��� ���� ���� n (2 �� n �� 100,000)���� �־�����.
�� �׽�Ʈ ���̽��� ��° �ٿ��� ���õ� �л����� ��ȣ�� �־�����. (��� �л����� 1���� n���� ��ȣ�� �ο��ȴ�.)

�� �׽�Ʈ ���̽����� �� �ٿ� ����ϰ�, �� �ٿ��� ������Ʈ ���� ������ ���� �л����� ���� ��Ÿ���� �ȴ�.
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
			if (i == arr[i] && team[i] == 0) {	//���ϴ� ������ �ƹ��� ���� ������ DFS����. �߰��� ����Ŭ ���� ������ ����. DFS�Ⱦ��� �ð��ʰ�����.
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
					if (cycle == 1 && here == cyclefirst) break;	//����Ŭ�� �̷������ ����Ŭ ������ ����� ���� �ѹ� �� ������ ������ ������.
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
			if (team[i] == 0 && want[i] == 1) {	//��尡 2�� �̻��̰� ���θ� ���ϴ� ������ ��� 1���� ���� ����Ŭ�� ���� ���
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