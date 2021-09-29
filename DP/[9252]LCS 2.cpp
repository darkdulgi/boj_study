/*
LCS(Longest Common Subsequence, ���� ���� �κ� ����)������ �� ������ �־����� ��, ����� �κ� ������ �Ǵ� ���� �� ���� �� ���� ã�� �����̴�.
���� ���, ACAYKP�� CAPCAK�� LCS�� ACAK�� �ȴ�.

ù° �ٰ� ��° �ٿ� �� ���ڿ��� �־�����. ���ڿ��� ���ĺ� �빮�ڷθ� �̷���� ������, �ִ� 1000���ڷ� �̷���� �ִ�.

ù° �ٿ� �Է����� �־��� �� ���ڿ��� LCS�� ���̸�, ��° �ٿ� LCS�� ����Ѵ�.
LCS�� ���� ������ ��쿡�� �ƹ��ų� ����ϰ�, LCS�� ���̰� 0�� ��쿡�� ��° ���� ������� �ʴ´�.


�� ���� ������ ���ڿ��� ��°�� 2���� �迭�� ����ֱ� ������ �ſ� ��ȿ������ �ڵ�. ������ �ǵ��� LCS�� ���̸� ���� �� �������� �ϴ� ��.
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
			if (s1[i - 1] == s2[j - 1])	//�� ���ڿ��� ���ڵ��� ���� �ϳ��� ���ϸ鼭 �� ���ڰ� ������ 1��,1�� ���� ���ڿ��� �� ���� ���ڸ� �߰�.
				sarr[i][j] = sarr[i - 1][j - 1] + s1[i - 1];
			else {	//�ٸ��� 1�� ���� ���ڿ��� 1�� ���� ���ڿ� �� ���̰� �� ���� ����.
				if (sarr[i][j - 1].length() >= sarr[i - 1][j].length())
					sarr[i][j] = sarr[i][j - 1];
				else
					sarr[i][j] = sarr[i - 1][j];
			}
		}
	}

	cout << sarr[s1.length()][s2.length()].length() << '\n' << sarr[s1.length()][s2.length()] << endl;
}