#include <iostream>
#include <Windows.h>
#include <ctime>

#include "Shooter.h"
#include "AbstractTarget.h"
#include "BiathlonTarget.h"
#include "GunTarget.h"

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
	const size_t winRate = 15;

	// створюємо два стрілця
	Shooter* bob = new Shooter("Bob");
	Shooter* mike = new Shooter("Mike");

	// створюємо дві мішені
	AbstractTarget* bt = new BiathlonTarget();
	AbstractTarget* gt = new GunTarget();

	// імітуємо гру

	size_t scores = 0;
	int x = 0;
	int y = 0;
	while (bob->getShotsRate() <= winRate && mike->getShotsRate() <= winRate)
	{
		if (!bt->canShot() || !gt->canShot())
		{
			cout << "Max target shots reached... Game over!\n";
			break;
		}
		Sleep(300);
		if (bt->canShot())
		{
			x = (rand() % 40) - 20;
			y = (rand() % 40) - 20;
			scores = bt->shot(x, y);
			bob->addShotsRate(scores);
			cout << bob->getName() << " shots at biathlon target with X[" << x << ";" << y << "]Y coords and gets +" << scores << " scores!\n";
		}
		Sleep(300);
		if (gt->canShot())
		{
			x = (rand() % 40) - 20;
			y = (rand() % 40) - 20;
			scores = gt->shot(x, y);
			mike->addShotsRate(scores);
			cout << mike->getName() << " shots at gun target with X[" << x << ";" << y << "]Y coords and gets +" << scores << " scores!\n";
		}
		cout << bob->getName() << " [" << bob->getShotsRate() << "] vs " << mike->getName() << " [" << mike->getShotsRate() << "]\n";
		Sleep(500);
	}
	string message;
	bob->getShotsRate() > mike->getShotsRate() ? message = "Bob has won the game!" : bob->getShotsRate() < mike->getShotsRate() ? message = "Mike has won the game!" : "Drawn game!";

	cout << message << endl;
	system("pause");

	delete bob;
	delete mike;
	delete gt;
	delete bt;
}
