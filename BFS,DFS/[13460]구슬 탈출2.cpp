/*
��ŸƮ��ũ���� �Ǹ��ϴ� ��̿� �峭�� �߿��� ���� �αⰡ ���� ��ǰ�� ���� Ż���̴�.
���� Ż���� ���簢�� ���忡 ���� ������ �Ķ� ������ �ϳ��� ���� ����, ���� ������ ������ ���� ������ �����̴�.
������ ���� ũ��� N, ���� ũ��� M�̰�, ���ǻ� 1��1ũ���� ĭ���� �������� �ִ�.
���� �ٱ� ��� ���� ��� ������ �ְ�, ���忡�� ������ �ϳ� �ִ�. ���� ������ �Ķ� ������ ũ��� ���忡�� 1��1ũ���� ĭ�� ���� ä��� �������̰�, ���� �ϳ��� �� �ִ�.
������ ��ǥ�� ���� ������ ������ ���ؼ� ������ ���̴�. �̶�, �Ķ� ������ ���ۿ� ���� �� �ȴ�.
�̶�, ������ ������ �ǵ帱 ���� ����, �߷��� �̿��ؼ� �̸� ���� ������ �Ѵ�. �������� ����̱�, ���������� ����̱�, �������� ����̱�, �Ʒ������� ����̱�� ���� �� ���� ������ �����ϴ�.
������ ���ۿ��� ���� ���ÿ� �����δ�. ���� ������ ���ۿ� ������ ����������, �Ķ� ������ ���ۿ� ������ �����̴�.
���� ������ �Ķ� ������ ���ÿ� ���ۿ� ������ �����̴�. ���� ������ �Ķ� ������ ���ÿ� ���� ĭ�� ���� �� ����. ��, ���� ������ �Ķ� ������ ũ��� �� ĭ�� ��� �����Ѵ�.
����̴� ������ �׸��ϴ� ���� �� �̻� ������ �������� ���� �� �����̴�.
������ ���°� �־����� ��, �ּ� �� �� ���� ���� ������ ������ ���� ���� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù ��° �ٿ��� ������ ����, ���� ũ�⸦ �ǹ��ϴ� �� ���� N, M (3 �� N, M �� 10)�� �־�����.
���� N���� �ٿ� ������ ����� ��Ÿ���� ���� M�� ���ڿ��� �־�����.
�� ���ڿ��� '.', '#', 'O', 'R', 'B' �� �̷���� �ִ�. '.'�� �� ĭ�� �ǹ��ϰ�, '#'�� ���� �̵��� �� ���� ��ֹ� �Ǵ� ���� �ǹ��ϸ�, 'O'�� ������ ��ġ�� �ǹ��Ѵ�.
'R'�� ���� ������ ��ġ, 'B'�� �Ķ� ������ ��ġ�̴�.
�ԷµǴ� ��� ������ �����ڸ����� ��� '#'�� �ִ�. ������ ������ �� �� �̸�, ���� ������ �Ķ� ������ �׻� 1���� �־�����.

�ּ� �� �� ���� ���� ������ ������ ���� ���� �� �ִ��� ����Ѵ�. ����, 10�� ���Ϸ� �������� ���� ������ ������ ���� ���� �� ������ -1�� ����Ѵ�.
*/
#include <iostream>
#include <queue>

using namespace std;

int xmove[4] = { 1,0,-1,0 };
int ymove[4] = { 0,1,0,-1 };
char arr[10][10] = { 0 };
struct status {
	pair<int, int> red;
	pair<int, int> blue;
	int move;
	int trynum;
};
pair<int, int> red;
pair<int, int> blue;
queue<status> q;
int minor = 2100000000;

bool redmove(int i) {
	arr[red.first][red.second] = '.';
	while (1) {
		red.first += xmove[i];
		red.second += ymove[i];
		if (arr[red.first][red.second] == 'O')
			return 1;
		if (arr[red.first][red.second] != '.') {
			red.first -= xmove[i];
			red.second -= ymove[i];
			arr[red.first][red.second] = 'R';
			return 0;
		}
	}
}

bool bluemove(int i) {
	arr[blue.first][blue.second] = '.';
	while (1) {
		blue.first += xmove[i];
		blue.second += ymove[i];
		if (arr[blue.first][blue.second] == 'O')
			return 1;
		if (arr[blue.first][blue.second] != '.') {
			blue.first -= xmove[i];
			blue.second -= ymove[i];
			arr[blue.first][blue.second] = 'B';
			return 0;
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c = cin.get();
			if (c == '\n') c = cin.get();
			arr[i][j] = c;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'R') {
				red.first = i;
				red.second = j;
			}
			else if (arr[i][j] == 'B') {
				blue.first = i;
				blue.second = j;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		if ((arr[red.first + xmove[i]][red.second + ymove[i]] != '#') || (arr[blue.first + xmove[i]][blue.second + ymove[i]] != '#')) {
			status a = { red,blue,i,0 };
			q.push(a);
		}
	}
	while (!q.empty()) {
		red.first = q.front().red.first;
		red.second = q.front().red.second;
		blue.first = q.front().blue.first;
		blue.second = q.front().blue.second;
		arr[red.first][red.second] = 'R';
		arr[blue.first][blue.second] = 'B';
		int i = q.front().move;
		int trynum = (q.front().trynum) + 1;
		if (trynum >= 11) {
			arr[red.first][red.second] = '.';
			arr[blue.first][blue.second] = '.';
			q.pop();
			continue;
		}
		pair<int, int> prevred = red;
		pair<int, int> prevblue = blue;

		if ((i == 0 && red.first > blue.first) || (i == 1 && red.second > blue.second) || (i == 2 && red.first < blue.first) || (i == 3 && red.second < blue.second)) {
			if (redmove(i) == 1) {
				q.pop();
				if (bluemove(i) == 1)
					continue;
				if (trynum < minor)
					minor = trynum;
				arr[blue.first][blue.second] = '.';
				continue;
			}
			if (bluemove(i) == 1) {
				arr[red.first][red.second] = '.';
				q.pop();
				continue;
			}
		}
		else {
			if (bluemove(i) == 1) {
				arr[red.first][red.second] = '.';
				q.pop();
				continue;
			}
			if (redmove(i) == 1) {
				arr[blue.first][blue.second] = '.';
				q.pop();
				if (trynum < minor)
					minor = trynum;
				continue;
			}
		}

		if (prevred == red && prevblue == blue) {
			arr[red.first][red.second] = '.';
			arr[blue.first][blue.second] = '.';
			q.pop();
			continue;
		}

		for (int ii = 0; ii < 4; ii++) {
			if (i == 0 && ii == 2) continue;
			else if (i == 1 && ii == 3) continue;
			else if (i == 2 && ii == 0) continue;
			else if (i == 3 && ii == 1) continue;
			if ((arr[red.first + xmove[ii]][red.second + ymove[ii]] != '#') || (arr[blue.first + xmove[ii]][blue.second + ymove[ii]] != '#')) {
				status a = { red,blue,ii,trynum };
				q.push(a);
			}
		}
		arr[red.first][red.second] = '.';
		arr[blue.first][blue.second] = '.';
		q.pop();
	}

	if (minor == 2100000000) cout << "-1" << endl;
	else cout << minor << endl;
}