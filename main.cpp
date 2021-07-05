
/*
Варіант 6а. Створення ієрархії класів на тему «Стрільба по мішенях»
Створити класи: «Абстрактна мішень» (методи «чи можна ще стріляти», «постріл», «координати цілі»),
підкласи «Біатлонна мішень», «Мішень для стрільби з гвинтівки».
Метод постріл задає координати на мішені, а його результатом буде кількість балів, отримана стрілком.
Метод координати цілі задає куди стріляти.
Створити клас «Стрілок», який може викликати метод постріл для мішені.
*/

//#include "stdafx.h"

#include <iostream>
#include <Windows.h>
#include <string>

#include "Shooter.h"
#include "AbstractTarget.h"
#include "BiathlonTarget.h"
#include "GunTarget.h"

using namespace std;

#define LINE cout <<"---------------------------------------------------------------------------\n";

#define MAXRANGEBIATLON 5
#define MAXRANGEGUN 7
#define MAXSHOTSCOUNTBICATLON 12
#define MAXSHOTSCOUNTGUN 21

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

	// створюємо три стрільця
	Shooter* user1 = new Shooter();
	Shooter* user2 = new Shooter();
	Shooter* user3 = new Shooter();

	// створюємо дві мішені
	AbstractTarget* target = nullptr;

	// змінна для збереження вибору мішені
	string choise;
	bool isGood = false;
	int ch = 0;
	do
	{
		try
		{
			cout << "[1] - Biathlon target\n[2] - Gun target\nChoose a target: ";
			getline(cin, choise);
			ch = stoi(choise);
			isGood = true;
			if (ch != 1 && ch != 2)
			{
				isGood = false;
				throw invalid_argument("Please, input only 1 or 2!\n");
			}
		}
		catch(const exception& ex)
		{
			cout << "Wrong type! "<< ex.what() <<"\nTry again.\n";
		}

	} while (!isGood);

	if(ch == 1 )
		target = new BiathlonTarget(MAXSHOTSCOUNTBICATLON, MAXRANGEBIATLON);
	else
		target = new GunTarget(MAXSHOTSCOUNTGUN, MAXRANGEGUN);

	user1->SetTarget(target);
	user2->SetTarget(target);
	user3->SetTarget(target);

	string tempName;
	cout << "Enter first shooter name: ";
	getline(cin, tempName);
	user1->SetName(tempName);
	cout << "Enter second shooter name: ";
	getline(cin, tempName);
	user2->SetName(tempName);
	cout << "Enter third shooter name: ";
	getline(cin, tempName);
	user3->SetName(tempName);

	// імітуємо гру

	float scores = 0;
	int x = 0;
	int y = 0;
	while (user1->GetShotsRate() <= winRate && user2->GetShotsRate() <= winRate && user3->GetShotsRate() <= winRate)
	{
		if (!target->canShot())
		{
			cout << "Max target shots reached... Game over!\n";
			break;
		}
		Sleep(300);
			scores = user1->Shot(x, y);
			cout << user1->GetName() << " shots at biathlon target with X[" << x << ";" << y << "]Y coords and gets +" << scores << " scores!\n";
		//}
		Sleep(300);
		if (!target->canShot())
		{
			cout << "Max target shots reached... Game over!\n";
			break;
		}
			scores = user2->Shot(x, y);
			cout << user2->GetName() << " shots at gun target with X[" << x << ";" << y << "]Y coords and gets +" << scores << " scores!\n";
		
		Sleep(300);
		if (!target->canShot())
		{
			cout << "Max target shots reached... Game over!\n";
			break;
		}
			scores = user3->Shot(x, y);
			cout << user3->GetName() << " shots at gun target with X[" << x << ";" << y << "]Y coords and gets +" << scores << " scores!\n";
		//}
		cout << user1->GetName() << " [" << user1->GetShotsRate() << "] vs " << user2->GetName() << " [" << user2->GetShotsRate() << "] vs " << user3->GetName() << "[" << user3->GetShotsRate() << "]\n";
		LINE
		Sleep(500);
	}
	string message;
	if (user1->GetShotsRate() > user2->GetShotsRate() && user1->GetShotsRate() > user3->GetShotsRate())
	{
		message = user1->GetName() + " has won the game!\n";
	}
	else if (user2->GetShotsRate() > user1->GetShotsRate() && user2->GetShotsRate() > user3->GetShotsRate())
	{
		message = user2->GetName() + " has won the game!\n";
	}
	else if (user3->GetShotsRate() > user1->GetShotsRate() && user3->GetShotsRate() > user2->GetShotsRate())
	{
		message = user3->GetName() + " has won the game!\n";
	}
	else if (user2->GetShotsRate() == user1->GetShotsRate() && user2->GetShotsRate() == user3->GetShotsRate())
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


