#include <iostream>
#include <string>
#include <Windows.h>

#ifdef max
#undef max
#endif

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	int timer;
	system("color 6");
retry:
	system("cls");
	cout << "Таймер (в часах): ";
	if (!(cin >> timer)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Пожалуйста, введите число!\n";
		Sleep(1000);
		goto retry;
	}
	else {
		if (timer > 24)
			timer = 24;
		else if (timer < 0)
			timer = 0;
		else
			timer = timer;

		system("cls");

		for (int hours = timer; hours >= 0; --hours) {
			int minutesRemain = hours * 60;
			hours--;
			if (hours <= 0)
				hours = 0;
			for (int minutes = minutesRemain; minutes >= 0; --minutes) {
				for (int mins = 59; mins >= 0; --mins) {
					for (int seconds = 59; seconds >= 0; --seconds) {
						cout << "Осталось: " << hours << ":" << mins << ":" << seconds;
						Sleep(100);
						system("cls");
					}
				}
			}
		}

		for (int i = 10; i > 0; i--) {
			string ending;
			if (i < 5 && i != 1)
				ending = "ы.";
			else if (i == 1)
				ending = "у.";
			else
				ending = ".";
			cout << "\t\t\tТаймер подошел к концу, выход из системы произойдет через " << i << " секунд" << ending;
			Sleep(1000);
			system("cls");
		}

		ExitWindows(EWX_LOGOFF, 0);
	}

	return 0;
}