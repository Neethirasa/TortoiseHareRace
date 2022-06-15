#include "Display.h"
#include<cstdlib>
template <typename T>
Display<T>::Display()
{
	arr = new T *[5];
	for (int i = 0; i < 5; i++)
	{
		arr[i] = new T[25];
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			arr[i][j] = ' ';
		}
	}
}


template <typename T>
void Display<T>::printDisplay()
{
	for (int i = 0; i < 26; i++)
		cout << "-";
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			cout << arr[i][j];
		}
		
		if (i >= 1 && i <= 3)
			cout << "=";
		else
			cout << "|";
		if (i == 2)
			cout << "*";
		cout << endl;
	}
	for (int i = 0; i < 26; i++)
		cout << "-";
	cout << endl;
}
template <typename T>
void Display<T>::emptyField()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if(arr[i][j]!='+')
				arr[i][j] = ' ';
		}
	}

}
template <typename T>
void Display<T>::setLocation(list<Hero> hls, list<Dragon> dls, list<Fighter> fls)
{
	list<Hero>::iterator it;
	int i = 0;
	// Make iterate point to begining and incerement it one by one till it reaches the end of list.
	for (it = hls.begin(); it != hls.end(); it++)
	{
		arr[it->getX()][it->getY()] = it->getCh();
	}
	list<Dragon>::iterator dr;
	for (dr = dls.begin(); dr != dls.end(); dr++)
	{
		arr[dr->getX()][dr->getY()] = dr->getCh();
	}
	list<Fighter>::iterator it1;
	// Make iterate point to begining and incerement it one by one till it reaches the end of list.
	for (it1 = fls.begin(); it1 != fls.end(); it1++)
	{
		arr[it1->getX()][it1->getY()] = it1->getCh();
	}
}
template<typename T>
void Display<T>::died(int i,int j)
{
	arr[i][j] = '+';
	//cout << "check" << endl;

}