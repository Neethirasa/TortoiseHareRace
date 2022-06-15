#include "Dragon.h"

Dragon::Dragon(int h, int s, int a, int i, int j,char c) :Character(h, s, a, i, j,c)
{
}
int Dragon::getX()
{
	return x;
}
int Dragon::getY()
{
	return y;
}
void Dragon::setX(int i)
{
	x = i;
}
char Dragon::getCh()
{
	return ch;
}