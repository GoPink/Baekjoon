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
	//한 줄을 공백포함 모든 걸 받아온다 but 개행은 x

	/*while (getline(cin, stt)) {
		cout << stt << endl;
	}*/
	//한 줄을 공백포함 모든 걸 받아온다 but 개행은 x

	/*while (fgets(str, 1001, stdin))
		cout << str;*/
	// fgets함수는 이용하면 개행문자까지 받아서 저장을 한다.

	/*while ((c = getchar()) != EOF)
		putchar(c);*/
	// 모든 문제의 답

	return 0;
}