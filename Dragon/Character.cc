#include "Character.h"

Character::Character(int h,int s,int a,int ii,int jj,char c)
{
	health = h;
	strength = s;
	armor = a;
	y = jj;
	x = ii;
	ch = c;
}
int Character::getX()
{
	return x;
}
int Character::getY()
{
	return y;
}
void Character::changeX(int i)
{
	if (ch != '+' && !(i == 1 && x >= 4) && !(i == -1 && x <= 0))
		x = x + i;

}
void Character::changeY(int j)
{
	if (ch != '+' && y<24)
		y = y + j;
}
char Character::getCh()
{
	return ch;
}
void Character::setArmor(int a)
{
	armor = a;
}
void Character::setHealth(int h)
{
	health = h;
}
void Character::setStrength(int s)
{
	strength = s;
}
int Character::getHealth()
{
	return health;
}
int Character::getStrength()
{
	return strength;
}
int Character::getArmor()
{
	return armor;
}