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
	if (ab < 0 && cd < 0) {
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