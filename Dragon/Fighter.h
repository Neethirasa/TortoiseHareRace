#ifndef FIGHTER
#define FIGHTER

#include"Character.h"
class Fighter :protected Character
{
public:
	Fighter(int, int, int, int, int, char);
	int getX();
	int getY();
	void changeX(int i);
	void changeY(int j);
	char getCh();
	int getHealth();
	int getStrength();
	int getArmor();
	void setArmor(int a);
	void setHealth(int h);
	void setStrength(int s);
};

#endif // !HERO
