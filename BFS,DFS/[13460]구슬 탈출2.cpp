/*
스타트링크에서 판매하는 어린이용 장난감 중에서 가장 인기가 많은 제품은 구슬 탈출이다.
구슬 탈출은 직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 빨간 구슬을 구멍을 통해 빼내는 게임이다.
보드의 세로 크기는 N, 가로 크기는 M이고, 편의상 1×1크기의 칸으로 나누어져 있다.
가장 바깥 행과 열은 모두 막혀져 있고, 보드에는 구멍이 하나 있다. 빨간 구슬과 파란 구슬의 크기는 보드에서 1×1크기의 칸을 가득 채우는 사이즈이고, 각각 하나씩 들어가 있다.
게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것이다. 이때, 파란 구슬이 구멍에 들어가면 안 된다.
이때, 구슬을 손으로 건드릴 수는 없고, 중력을 이용해서 이리 저리 굴려야 한다. 왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기와 같은 네 가지 동작이 가능하다.
각각의 동작에서 공은 동시에 움직인다. 빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다.
빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다. 빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다. 또, 빨간 구슬과 파란 구슬의 크기는 한 칸을 모두 차지한다.
기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.
보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성하시오.

첫 번째 줄에는 보드의 세로, 가로 크기를 의미하는 두 정수 N, M (3 ≤ N, M ≤ 10)이 주어진다.
다음 N개의 줄에 보드의 모양을 나타내는 길이 M의 문자열이 주어진다.
이 문자열은 '.', '#', 'O', 'R', 'B' 로 이루어져 있다. '.'은 빈 칸을 의미하고, '#'은 공이 이동할 수 없는 장애물 또는 벽을 의미하며, 'O'는 구멍의 위치를 의미한다.
'R'은 빨간 구슬의 위치, 'B'는 파란 구슬의 위치이다.
입력되는 모든 보드의 가장자리에는 모두 '#'이 있다. 구멍의 개수는 한 개 이며, 빨간 구슬과 파란 구슬은 항상 1개가 주어진다.

최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 출력한다. 만약, 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다.
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