/*2차원 좌표 평면 위의 두 선분 L1, L2가 주어졌을 때, 두 선분이 교차하는지 아닌지 구해보자. 한 선분의 끝 점이 다른 선분이나 끝 점 위에 있는 것도 교차하는 것이다.
L1의 양 끝 점은 (x1, y1), (x2, y2), L2의 양 끝 점은 (x3, y3), (x4, y4)이다.

첫째 줄에 L1의 양 끝 점 x1, y1, x2, y2가, 둘째 줄에 L2의 양 끝 점 x3, y3, x4, y4가 주어진다.

L1과 L2가 교차하면 1, 아니면 0을 출력한다.
*/
#include <iostream>
#define ll long long
using namespace std;

struct dot {
	ll x, y;
};
struct line {
	dot d1, d2;
};
ll ccw(dot a, dot b, dot c) {
	ll s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (s < 0) return -1;
	else if (s > 0) return 1;
	else return 0;
}

bool ismeet(line l1, line l2) {
	dot a = l1.d1;
	dot b = l1.d2;
	dot c = l2.d1;
	dot d = l2.d2;
	ll ab = ccw(a, b, c) * ccw(a, b, d);
	ll cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab <= 0 && cd <= 0) {
		if (ab == 0 && cd == 0) {
			if (a.x > b.x)swap(a, b);
			if (c.x > d.x)swap(c, d);
			if (a.x == b.x && a.y > b.y)swap(a, b);
			if (c.x == d.x && c.y > d.y)swap(c, d);
			if (a.x > d.x || b.x < c.x)
				return 0;
			if (a.x == b.x && (a.y > d.y || b.y < c.y))
				return 0;
		}
		return 1;
	}
	return 0;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	line a, b;
	cin >> a.d1.x >> a.d1.y >> a.d2.x >> a.d2.y;
	cin >> b.d1.x >> b.d1.y >> b.d2.x >> b.d2.y;

	cout << ismeet(a, b);
}