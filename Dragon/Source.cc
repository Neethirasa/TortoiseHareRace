#include"Display.cc"
#include"Display.h"
#include"Dragon.h"
#include<cstdlib>
#include<time.h>
#include"Hero.h"
#include"Fighter.h"
list<Hero> hls;
list<Dragon> dls;
list<Fighter> FLS;
Display<char> display;
void initiateGame();
void moveCharacters();
bool gameFinished();
void makeFighter();
void checkCollisions();
int dragonControl = rand()%4;
int herosAlive = 2;
int main()
{
	initiateGame();
	while (!gameFinished())
	{
		display.printDisplay();
		moveCharacters();
		checkCollisions();
		if (rand() % 100 < 60)
			makeFighter();
	}
	display.printDisplay();

}
void initiateGame()
{
	srand((unsigned)time(NULL));
	Hero t(15, 3, 3,rand()%5,0,'T');
	Hero h(15, 5, 1,rand()%5,0,'H');
	Dragon d(INT_MAX, 0, 0, dragonControl, 24, 'D');
	hls.push_back(t);
	hls.push_back(h);
	dls.push_back(d);
	display.setLocation(hls,dls,FLS);
	//ls.push_back(h);
}
void makeFighter()
{
	int ra = rand() % 3;
	if (ra == 0)
	{
		int st = rand() % 2;
		Fighter f(5, st + 4, 0, rand() % 5, 24, 'p');
		FLS.push_back(f);
	}
	if (ra == 1)
	{
		int st = rand() % 4;
		Fighter f(5, st + 8, 0, rand() % 5, 24, 'b');
		FLS.push_back(f);
	}
	if (ra == 2)
	{
		int st = rand() % 3;
		Fighter f(5, st + 6, 0, rand() % 5, 24, 'd');
		FLS.push_back(f);
	}
}
void moveCharacters()
{
	display.emptyField();
	list<Hero>::iterator hr;
	for (hr = hls.begin(); hr != hls.end(); hr++)
	{
		int random = rand() % 2;
		if (random == 0)
			hr->changeX(1);
		else
			hr->changeX(-1);
		hr->changeY(1);
	}
	list<Dragon>::iterator dr;
	for (dr = dls.begin(); dr != dls.end(); dr++)
	{
		if (dragonControl%4 == 0)
			dr->setX(1);
		else if (dragonControl%4 == 1)
			dr->setX(2);
		else if (dragonControl%4 == 2)
			dr->setX(3);
		else if (dragonControl%4 == 3)
			dr->setX(2);
		dragonControl++;
	}
	list<Fighter>::iterator fr;
	for (fr = FLS.begin(); fr != FLS.end(); fr++)
	{
		int random = rand() % 2;
		if (random == 0)
			fr->changeX(1);
		else
			fr->changeX(-1);
		fr->changeY(-1);
	}
	display.setLocation(hls,dls,FLS);
}
bool gameFinished()
{
	list<Hero>::iterator it;
	for (it = hls.begin(); it != hls.end(); it++)
	{
		if (it->getX() >= 1 && it->getX() <= 3 && it->getY() == 24 && it->getHealth()>0)
		{
			cout << it->getCh() << " Wins the Game" << endl;
			return true;
		}
	}
	if (herosAlive > 0)
		return false;
	else
	{
		cout << "Both Heros Died!!" << endl;
		return true;
	}
}
void checkCollisions()
{
	bool haroldPopped = false;
	bool timmyPopped = false;

	list<Hero>::iterator hr;
	for (hr = hls.begin(); hr != hls.end();)
	{
		bool check1 = false;
		bool check2 = false;
		list<Dragon>::iterator dr;
		int i = 0;

		for (dr = dls.begin(); dr != dls.end(); dr++)
		{
			if (dr->getX() == hr->getX() && dr->getY() == hr->getY())
			{
				hr->setHealth(0);
				cout << hr->getCh() << " Died " << endl;
				display.died(hr->getX(), hr->getY());
				hr = hls.erase(hr);
				herosAlive--;
				check1 = true;
			}
			else
				check1 = false;
		}
		if (herosAlive == 0 || check1)
			break;
		list<Fighter>::iterator fr;
		for (fr = FLS.begin(); fr != FLS.end();)
		{
			if (hr->getX() == fr->getX() && hr->getY() == fr->getY())
			{
				hr->setHealth(hr->getHealth()+(hr->getArmor() - fr->getStrength()));
				fr->setHealth(fr->getHealth() - hr->getStrength());
				if (hr->getHealth() <= 0)
				{
					cout << hr->getCh() << " Died " << endl;
					display.died(hr->getX(), hr->getY());
					hr = hls.erase(hr);
					herosAlive--;
					check2 = true;
				}
				if (fr->getHealth() <= 0)
				{
					fr = FLS.erase(fr);
				}
				break;
				//cout <<hr->getCh()<< hr->getHealth() << endl;
			}
			else
			{
				++fr;
				check2 = false;
			}
		}
		if (herosAlive == 0 || check2==true)
			break;

		if ((!check1 && !check2))
		{
			++hr;
		}



	}

}
