#include "Hero.h"

Hero::Hero(int h, int s, int a, int i, int j,char c) :Character(h, s, a, i, j,c)
{
}
int Hero::getX()
{
	return x;
}
int Hero::getY()
{
	return y;
}
void Hero::changeX(int i)
{
	if (ch!='+'&& !(i == 1 && x >= 4) && !(i == -1 && x <= 0))
		x = x + i;

}
void Hero::changeY(int j)
{
	if(ch != '+' && y<24)
		y = y + j;
}
char Hero:: getCh()
{
	return ch;
}
void Hero::setArmor(int a)
{
	armor = a;
}
void Hero::setHealth(int h)
{
	health = h;
}
void Hero::setStrength(int s)
{
	strength = s;
}
int Hero::getHealth()
{
	return health;
}
int Hero::getStrength()
{
	return strength;
}
int Hero::getArmor()
{
	return armor;
}