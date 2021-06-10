#include <iostream>
#include <Windows.h>
#include <ctime>

#include "Shooter.h"
#include "AbstractTarget.h"
#include "BiathlonTarget.h"
#include "GunTarget.h"
#include <string>

#define LINE cout <<"---------------------------------------------------------------------------\n";

using namespace std;

void startGame();

int main()
{
	// для генерації випадкових чисел
	srand(size_t(time(NULL)));
	
	// починаємо гру
	startGame();

	return 0;
}

void startGame()
{
	// переможний рівень
	const size_t winRate = 10;

	// створюємо два стрільця
	Shooter* user1 = new Shooter();
	Shooter* user2 = new Shooter();
	Shooter* user3 = new Shooter();

	// створюємо дві мішені
	AbstractTarget* target = nullptr;

	// змінна для збереження вибору мішені
	char choise = 0;
	cout << "[1] - Biathlon target\n[2] - Gun target\nChoose a target: ";
	cin >> choise;
	cin.ignore();
	if (choise == 1)
		target = new BiathlonTarget();
	else
		target = new GunTarget();

	string tempName;
	cout << "Enter first shooter name: ";
	getline(cin, tempName);
	user1->setName(tempName);
	cout << "Enter second shooter name: ";
	getline(cin, tempName);
	user2->setName(tempName);
	cout << "Enter third shooter name: ";
	getline(cin, tempName);
	user3->setName(tempName);

	// імітуємо гру

	float scores = 0;
	int x = 0;
	int y = 0;
	while (user1->getShotsRate() <= winRate && user2->getShotsRate() <= winRate && user3->getShotsRate() <= winRate)
	{
		if (!target->canShot())
		{
			cout << "Max target shots reached... Game over!\n";
			break;
		}
		Sleep(300);
		if (target->canShot())
		{
			x = (rand() % 40) - 20;
			y = (rand() % 40) - 20;
			scores = target->shot(x, y);
			user1->addShotsRate(scores);
			cout << user1->getName() << " shots at biathlon target with X[" << x << ";" << y << "]Y coords and gets +" << scores << " scores!\n";
		}
		Sleep(300);
		if (target->canShot())
		{
			x = (rand() % 40) - 20;
			y = (rand() % 40) - 20;
			scores = target->shot(x, y);
			user2->addShotsRate(scores);
			cout << user2->getName() << " shots at gun target with X[" << x << ";" << y << "]Y coords and gets +" << scores << " scores!\n";
		}
		Sleep(300);
		if (target->canShot())
		{
			x = (rand() % 40) - 20;
			y = (rand() % 40) - 20;
			scores = target->shot(x, y);
			user3->addShotsRate(scores);
			cout << user3->getName() << " shots at gun target with X[" << x << ";" << y << "]Y coords and gets +" << scores << " scores!\n";
		}
		cout << user1->getName() << " [" << user1->getShotsRate() << "] vs " << user2->getName() << " [" << user2->getShotsRate() << "] vs " << user3->getName() << "[" << user3->getShotsRate() << "]\n";
		LINE
		Sleep(500);
	}
	string message;
	if (user1->getShotsRate() > user2->getShotsRate() && user1->getShotsRate() > user3->getShotsRate())
	{
		message = user1->getName() + " has won the game!\n";
	}
	else if (user2->getShotsRate() > user1->getShotsRate() && user2->getShotsRate() > user3->getShotsRate())
	{
		message = user2->getName() + " has won the game!\n";
	}
	else if (user3->getShotsRate() > user1->getShotsRate() && user3->getShotsRate() > user2->getShotsRate())
	{
		message = user3->getName() + " has won the game!\n";
	}
	else if (user2->getShotsRate() == user1->getShotsRate() && user2->getShotsRate() == user3->getShotsRate())
	{
		message = "Drawn game!\n";
	}
	else
		message = "No winner as there are some equal results\n";
	cout << message << endl;
	system("pause");

	delete user1;
	delete user2;
	delete user3;
	delete target;
}
