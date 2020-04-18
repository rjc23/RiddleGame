#include <iostream>
#include <cstdlib>
using namespace std;	

extern void pause(int dur);
void animals(animal** a)
{	
	for(int i = 0; i < 3; i++)
	{
		if(a[i]->getInitial() == 'c')
		{
			system("clear");
			cout << "A cat.." << endl << endl;
			cout << "      ╱╲    ╱╲  ╭━╮" << endl; 
			cout << "     ╱╱╲╲__╱╱╲╲ ╰╮┃" << endl;
			cout << "     ▏┏┳╮ ╭┳┓ ▕  ┃┃" << endl;
			cout << "     ▏╰┻┛▼┗┻╯ ▕  ┃┃" << endl;
			cout << "     ╲  ╰┻╯   ╱▔▔ ┃" << endl;
			cout << "      ╰━┳━━━ ╯    ┃" << endl;
		 	cout << "        ┃┏┓┣━━┳┳┓┃" << endl;
			cout << "        ┗┛┗┛  ┗┛┗┛" << endl;
			pause(1);

			system("clear");
			cout << "A cat.." << endl << endl;
			cout << "      ╱╲    ╱╲  ╭━╮" << endl; 
			cout << "     ╱╱╲╲__╱╱╲╲ ╰╮┃" << endl;
			cout << "     ▏┏┳╮ ╭┳┓ ▕  ┃┃" << endl;
			cout << "  _  ▏╰┻┛▼┗┻╯ ▕  ┃┃" << endl;
			cout << "     ╲  ╰┻╯   ╱▔▔ ┃" << endl;
			cout << "  /  |╰━┳━━━ ╯    ┃" << endl;
		 	cout << " " << a[i]->makeSound(1) << "   ┃┏┓┣━━┳┳┓┃" << endl;
			cout << "        ┗┛┗┛  ┗┛┗┛" << endl;
			pause(1);
		}

		else if (a[i]->getInitial() == 'd')
		{
			system("clear");
			cout << "A dog.." << endl << endl;
			cout << "    ╱▏      ▕╲▕╲" << endl;
			cout << "    ▏▏      ▕▏▔▔╲" << endl;
			cout << "    ▏╲      ╱ ▔ ▔╲" << endl;
			cout << "    ╲▏▔▔▔▔▔▔╯╯╰┳━━▀" << endl;
			cout << "     ▏╯╯╯╯╯╯╯╯╱┃" << endl;
			cout << "     ┃┏┳┳━━━┫┣┳┃" << endl;
			cout << "     ┃┃┃┃   ┃┃┃┃" << endl;
			cout << "     ┗┛┗┛   ┗┛┗┛" << endl;
			pause(1);
			system("clear");
			cout << "A dog.." << endl << endl;
			cout << "    ╱▏      ▕╲▕╲" << endl;
			cout << "    ▏▏      ▕▏▔▔╲" << endl;
			cout << "    ▏╲      ╱ ▔ ▔╲" << endl;
			cout << "    ╲▏▔▔▔▔▔▔╯╯╰┳━━▀" << endl;
			cout << "     ▏╯╯╯╯╯╯╯╯╱┃ / | \\" << endl;
			cout << "     ┃┏┳┳━━━┫┣┳┃  " << a[i]->makeSound(1) << endl;
			cout << "     ┃┃┃┃   ┃┃┃┃" << endl;
			cout << "     ┗┛┗┛   ┗┛┗┛" << endl;
			pause(1);
		}
		else if(a[i]->getInitial() == 'm')
		{
			system("clear");
			cout << "A mouse.." << endl << endl;
			cout << "                    ___" << endl;
			cout << "           _  _  .-'   '-." << endl;
			cout << "          (.)(.)/         \\  " << endl;
			cout << "           /@@             ;          /   " << endl;
			cout << "          o_\\\\-mm-......-mm`~~~~~~~~~' " << endl;
			pause(1);
			system("clear");
			cout << "A mouse.." << endl << endl;
			cout << "                    ___" << endl;
			cout << "           _  _  .-'   '-." << endl;
			cout << "          (.)(.)/         \\  " << endl;
			cout << a[i]->makeSound(1) << "  _\\  /@@             ;          /   " << endl;
			cout << "        / o_\\\\-mm-......-mm`~~~~~~~~~' " << endl;
			pause(1);
		}
	}
}
