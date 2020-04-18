#include <iostream>
#include <ctime>
#include <string>

using namespace std;
string extend(string a);
string remove(string a);
extern void pause(int dur);
//take in boat location and 

void boat(int location)
{
	string a;
	if(location == 1)
		a = " ";
	else if (location == 0)
		a = "                      ";

		for(int i = 0; i < 4; i ++)
		{
				system("clear");
				cout << "     Left Riverbank       Right Riverbank" << endl << endl;
				cout <<  a << "           |"<< endl;
				cout <<  a << "          /|        "<< endl;
				cout <<  a << "         / |\\"<< endl;
				cout <<  a << "        /  | \\"<< endl;
				cout <<  a << "       /   || \\"<< endl;
				cout <<  a << "      /    | | \\"<< endl;
				cout <<  a << "     /     | |  \\"<< endl;
				cout <<  a << "    /      | |   \\"<< endl;
				cout <<  a << "   /       ||     \\"<< endl;
				cout <<  a << "  /        /       \\"<< endl;
				cout <<  a << " /________/         \\"<< endl;
				cout <<  a << " ________/__________--/"<< endl;
				cout <<  a << " \\___________________/"<< endl << endl;

				if(location == 1)
					a = extend(a);
				if(location == 0)
					a = remove(a);

				pause(1);
		}
}

string extend(string a)
{
    a.append("       ");
    return a;
}

string remove(string a)
{
	a.erase(1, 7);
    return a;
}
