#include <iostream>

using namespace std;

void Day(int day) {
	if (day % 7 == 1) printf("MOM");
	else if (day % 7 == 2) printf("TUE");
	else if (day % 7 == 3) printf("WED");
	else if (day % 7 == 4) printf("THU");
	else if (day % 7 == 5) printf("FRI");
	else if (day % 7 == 6) printf("SAT");
	else printf("SUN");
}

int main(void) {
	int m = 0, d = 0;
	scanf("%d %d", &m, &d);
	switch (m)
	{
	case 1: case 10:
		Day(d);
		break;
	case 5:
		Day(d + 1);
		break;
	case 8:
		Day(d + 2);
		break;
	case 2: case 3: case 11:
		Day(d + 3);
		break;
	case 6:
		Day(d + 4);
		break;
	case 9: case 12:
		Day(d + 5);
		break;
	case 4: case 7:
		Day(d + 6);
		break;
	default:
		break;
	}
}