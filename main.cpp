/*
Variant 6a. Creating a class hierarchy on the topic "Target Shooting".
Create classes: "Abstract Target" (methods: "can shoot", "shot", "target coordinates"),
subclasses: "Biathlon Target", "Rifle Target".
The "shot" method takes coordinates on the target and returns the score obtained.
The "target coordinates" method defines where to shoot.
Create a "Shooter" class that can call the shot method for a target.
*/

#include <chrono>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <thread>

#include "AbstractTarget.h"
#include "BiathlonTarget.h"
#include "GunTarget.h"
#include "Shooter.h"

using namespace std;

#define LINE cout << "---------------------------------------------------------------------------\n";

namespace
{
	constexpr int MAXRANGEBIATLON = 5;
	constexpr int MAXRANGEGUN = 10;
	constexpr size_t MAXSHOTSCOUNTBIATHLON = 12;
	constexpr size_t MAXSHOTSCOUNTGUN = 21;
	constexpr size_t WINRATE = 15;

	void Pause(unsigned int milliseconds)
	{
		this_thread::sleep_for(chrono::milliseconds(milliseconds));
	}

	const char* GetTargetName(int choice)
	{
		return choice == 1 ? "biathlon target" : "gun target";
	}

	void PrintShotResult(const Shooter& shooter, int targetChoice, int x, int y, float scores)
	{
		cout << shooter.GetName() << " shots at " << GetTargetName(targetChoice)
			<< " with coords (" << x << "; " << y << ") and gets +" << scores << " scores!\n";
	}
}

void startGame();

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	startGame();
	return 0;
}

void startGame()
{
	Shooter user1;
	Shooter user2;
	Shooter user3;

	unique_ptr<AbstractTarget> target;

	string choice;
	bool isGood = false;
	int ch = 0;

	do
	{
		try
		{
			cout << "[1] - Biathlon target\n[2] - Gun target\nChoose a target: ";
			getline(cin, choice);
			ch = stoi(choice);
			isGood = true;

			if (ch != 1 && ch != 2)
			{
				isGood = false;
				throw invalid_argument("Please, input only 1 or 2!");
			}
		}
		catch (const exception& ex)
		{
			cout << "Wrong type! " << ex.what() << "\nTry again.\n";
		}
	} while (!isGood);

	if (ch == 1)
	{
		target = make_unique<BiathlonTarget>(MAXSHOTSCOUNTBIATHLON, MAXRANGEBIATLON);
	}
	else
	{
		target = make_unique<GunTarget>(MAXSHOTSCOUNTGUN, MAXRANGEGUN);
	}

	user1.SetTarget(target.get());
	user2.SetTarget(target.get());
	user3.SetTarget(target.get());

	string tempName;
	cout << "Enter first shooter name: ";
	getline(cin, tempName);
	user1.SetName(tempName);

	cout << "Enter second shooter name: ";
	getline(cin, tempName);
	user2.SetName(tempName);

	cout << "Enter third shooter name: ";
	getline(cin, tempName);
	user3.SetName(tempName);

	float scores = 0;
	int x = 0;
	int y = 0;

	while (user1.GetShotsRate() <= WINRATE &&
		user2.GetShotsRate() <= WINRATE &&
		user3.GetShotsRate() <= WINRATE)
	{
		if (!target->canShot())
		{
			cout << "Max target shots reached... Game over!\n";
			break;
		}

		Pause(300);
		scores = user1.Shot(x, y);
		PrintShotResult(user1, ch, x, y, scores);

		if (!target->canShot())
		{
			cout << "Max target shots reached... Game over!\n";
			break;
		}

		Pause(300);
		scores = user2.Shot(x, y);
		PrintShotResult(user2, ch, x, y, scores);

		if (!target->canShot())
		{
			cout << "Max target shots reached... Game over!\n";
			break;
		}

		Pause(300);
		scores = user3.Shot(x, y);
		PrintShotResult(user3, ch, x, y, scores);

		cout << user1.GetName() << " [" << user1.GetShotsRate() << "] vs "
			<< user2.GetName() << " [" << user2.GetShotsRate() << "] vs "
			<< user3.GetName() << " [" << user3.GetShotsRate() << "]\n";
		LINE
		Pause(500);
	}

	string message;
	if (user1.GetShotsRate() > user2.GetShotsRate() && user1.GetShotsRate() > user3.GetShotsRate())
	{
		message = user1.GetName() + " has won the game!\n";
	}
	else if (user2.GetShotsRate() > user1.GetShotsRate() && user2.GetShotsRate() > user3.GetShotsRate())
	{
		message = user2.GetName() + " has won the game!\n";
	}
	else if (user3.GetShotsRate() > user1.GetShotsRate() && user3.GetShotsRate() > user2.GetShotsRate())
	{
		message = user3.GetName() + " has won the game!\n";
	}
	else if (user1.GetShotsRate() == user2.GetShotsRate() && user2.GetShotsRate() == user3.GetShotsRate())
	{
		message = "Drawn game!\n";
	}
	else
	{
		message = "No winner as there are some equal results\n";
	}

	cout << message << endl;
	system("pause");
}
