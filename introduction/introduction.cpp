#include <iostream>
using namespace std;

extern void dog();
extern void cat();
extern void pause(int dur);

int main(void)
{
	system("clear");

	cout << "WELCOME TO THE RIVERBANK RIDDLE!" << endl;
	cout << "contunue: (y/n)" << endl;
	char answer = 'n';
	while (answer != 'y')
	{
		cin >> answer;
	}

	system("clear");
	pause(1);
	cout << "In this riddle you are standing on one side of a riverbank" << endl << endl;
	pause(3);
	cout << "The river is too deep and too wide to safetly swim across" << endl << endl;
	pause(3);
	cout << "However, there is a boat, that can safetly transport you and one other to the other side of the river" << endl << endl;
	pause(4);
	cout << "You have 3 animals with you that you need to safetly transport across the river" << endl << endl;
	pause(4);
	cout << "They are..." << endl << endl;
	pause(3);
	cout << "contunue: (y/n)" << endl;
	char answer2 = 'n';
	while (answer2 != 'y')
	{
		cin >> answer2;
	}

	system("clear");
	pause(2);
	dog();
	pause(1);
	cat();


	return 0;
}
