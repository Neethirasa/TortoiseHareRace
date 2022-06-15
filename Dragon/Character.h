#ifndef CHARACTER
#define CHARACTER

class Character
{
protected:
	int health;
	int strength;
	int armor;
	int x;
	int y;
	char ch;
public:
	Character(int,int,int,int,int,char);
	int virtual  getX();
	int virtual getY();
	int virtual getHealth();
	int virtual getStrength();
	int virtual getArmor();
	void virtual setArmor(int a);
	void virtual setHealth(int h);
	void virtual setStrength(int s);
	void virtual changeX(int i);
	void virtual changeY(int j);
	char virtual getCh();
};

#endif // !1
