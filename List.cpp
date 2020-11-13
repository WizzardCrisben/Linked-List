#include "list"
#include <iostream>
#include<conio.h>
#include <iterator>
#include <array>
#include <string>

using namespace std;

list <string> Pandemics;
list <string> Cormobidities;
int arrSize = 3;
string tempValue;
int restoreCount;

void showlist(list <string> g);
void swap(string, string);

int main()
{
	string arr1[] = { "Spanish Flue", "Ebola", "COVID-19" };
	string arr2[] = { "HIV", "TB", "Cancer" };
	string value;

	cout << "Initializing Pandemics!!!!!!" << endl;
	cout << "-----------------------------" << endl;
	for (int i = 0; i < arrSize; i++)
	{
		Pandemics.push_back(arr1[i]);
		cout << (i + 1) << ". [" << arr1[i] << "] added to Pandemics" << endl;
	}

	cout << "\nDisplaying Comorbidities List" << endl;
	cout << "------------------------------------------------" << endl;
	showlist(Pandemics);

	cout << "\nInitializing Comorbidities!!!!!!" << endl;
	cout << "-----------------------------------" << endl;
	for (int i = 0; i < arrSize; i++)
	{
		Cormobidities.push_back(arr2[i]);
		cout << (i + 1) << ". [" << arr2[i] << "] added to Comorbidities" << endl;
	}

	cout << "\nDisplaying Comorbidities List" << endl;
	cout<<"------------------------------------------------" << endl;
	showlist(Cormobidities);

	for (int i = 0; i < arrSize; i++)
	{
		value = Cormobidities.back();
		Cormobidities.pop_back();
		Pandemics.push_back(value);
		cout << value << " moved from comorbi to pande" << endl;
	}

	cout << "\n\nPANDEMICS AFTER MREGING" << endl;
	showlist(Pandemics);

	swap("TB", "COVID-19");
	cout << "\n\nAFTER SWAP" << endl;

	showlist(Pandemics);
	_getch();
	return 0;
}

void showlist(list <string> healthlist)
{
	list <string> ::iterator itr;
	for (itr = healthlist.begin(); itr != healthlist.end(); ++itr)
		cout << *itr << "	";
	cout <<'\n';
}

void swap(string str1, string str2)
{
	restoreCount = 0;
	for (int i = 0; i < arrSize; i++)
	{
		tempValue = Pandemics.back();
		if (str1 == tempValue)
		{
			Pandemics.pop_back();
			Cormobidities.push_back(str2);
			cout << "\nElement " << tempValue << " has been found and replaced by " << str2 <<"\n\n"<< endl;
			restoreCount++;
		}
		else if (str2 == tempValue)
		{
			Pandemics.pop_back();
			Cormobidities.push_back(str1);
			cout << "\nElement " << tempValue << " has been found and replaced by " << str1 << "\n\n" << endl;
			restoreCount++;
		}
		else
		{
			Pandemics.pop_back();
			Cormobidities.push_back(tempValue);
			restoreCount++;
		}
	}

	cout << "\n\nRestoring elements from comor to pande" << endl;
	for (int i = 0; i < restoreCount; i++)
	{
		tempValue = Cormobidities.back();
		Cormobidities.pop_back();
		Pandemics.push_back(tempValue);
		cout << "Element " << Pandemics.back() << " restored from cormo" << endl;
	}
}