#include <iostream>
#include <string>

using namespace std;
int main(void) {
	char str[1001];
	char c = 0;
	string stt;
	freopen("input.txt", "r", stdin);
	
	/*while (cin.getline(str, 1001)) {
		cout << str << endl;
	}*/
	//�� ���� �������� ��� �� �޾ƿ´� but ������ x

	/*while (getline(cin, stt)) {
		cout << stt << endl;
	}*/
	//�� ���� �������� ��� �� �޾ƿ´� but ������ x

	/*while (fgets(str, 1001, stdin))
		cout << str;*/
	// fgets�Լ��� �̿��ϸ� ���๮�ڱ��� �޾Ƽ� ������ �Ѵ�.

	/*while ((c = getchar()) != EOF)
		putchar(c);*/
	// ��� ������ ��

	return 0;
}