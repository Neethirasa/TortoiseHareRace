#ifndef DISPLAY
#define DISPLAY
#include"Character.h"
#include"Hero.h"
#include"Dragon.h"
#include"Fighter.h"
#include<iostream> 
#include<list>
using namespace std;
template <typename T>
class Display
{
	T ** arr;
public:
	Display();
	void printDisplay();
	//void initiateGame();
	void setLocation(list<Hero> hls, list<Dragon> dls, list<Fighter> fls);
	void emptyField();
	void died(int, int);
};

#endif
