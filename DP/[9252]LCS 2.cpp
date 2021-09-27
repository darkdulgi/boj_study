/*
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를, 둘째 줄에 LCS를 출력한다.
LCS가 여러 가지인 경우에는 아무거나 출력하고, LCS의 길이가 0인 경우에는 둘째 줄을 출력하지 않는다.


※ 밑의 정답은 문자열을 통째로 2차원 배열에 집어넣기 때문에 매우 비효율적인 코드. 문제의 의도는 LCS의 길이만 구한 뒤 역추적을 하는 것.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	string s1, s2;
	cin >> s1 >> s2;
	string sarr[1001][1001];

	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1])	//두 문자열의 문자들을 서로 하나씩 비교하면서 두 문자가 같으면 1행,1열 작은 문자열에 그 같은 문자를 추가.
				sarr[i][j] = sarr[i - 1][j - 1] + s1[i - 1];
			else {	//다르면 1행 작은 문자열과 1열 작은 문자열 중 길이가 긴 것을 대입.
				if (sarr[i][j - 1].length() >= sarr[i - 1][j].length())
					sarr[i][j] = sarr[i][j - 1];
				else
					sarr[i][j] = sarr[i - 1][j];
			}
		}
	}

	cout << sarr[s1.length()][s2.length()].length() << '\n' << sarr[s1.length()][s2.length()] << endl;
}