#ifndef DRAGON
#define DRAGON

#include"Character.h"
class Dragon :protected Character
{
public:
	Dragon(int, int, int, int, int,char);
	int getX();
	int getY();
	void setX(int i);
	char getCh();

};

#endif // !HERO
