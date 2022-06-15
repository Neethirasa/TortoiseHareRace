#ifndef HERO
#define HERO

#include"Character.h"
class Hero :protected Character
{
public:
	Hero(int, int, int, int, int,char);
	int getX();
	int getY();
	int getHealth();
	int getStrength();
	int getArmor();
	void setArmor(int a);
	void setHealth(int h);
	void setStrength(int s);
	void changeX(int i);
	void changeY(int j);
	char getCh();
};

#endif // !HERO
