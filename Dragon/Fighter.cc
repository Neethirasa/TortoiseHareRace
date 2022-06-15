#include "Fighter.h"

Fighter::Fighter(int h, int s, int a, int i, int j, char c) :Character(h, s, a, i, j, c)
{
}
int Fighter::getX()
{
	return x;
}
int Fighter::getY()
{
	return y;
}
void Fighter::changeX(int i)
{
	if (!(i == 1 && x >= 4) && !(i == -1 && x <= 0))
		x = x + i;

}
void Fighter::changeY(int j)
{
	if (y>0)
		y = y + j;
}
char Fighter::getCh()
{
	return ch;
}
void Fighter::setArmor(int a)
{
	armor = a;
}
void Fighter::setHealth(int h)
{
	health = h;
}
void Fighter::setStrength(int s)
{
	strength = s;
}
int Fighter::getHealth()
{
	return health;
}
int Fighter::getStrength()
{
	return strength;
}
int Fighter::getArmor()
{
	return armor;
}