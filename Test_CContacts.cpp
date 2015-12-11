// test CContacts
#include <iostream>
#include <string>
#include "CContacts.h"
void ShowMenu();
static std::string GetString();
int main(){
	CContacts cc;
	ShowMenu();
	std::string choice = GetString();
	while(choice != "quit"){
		if(choice == "add"){
			cc.Add();
		}
		else if(choice == "del"){
			cc.Del();
		}
		else if(choice == "update"){
			cc.Update();
		}
		else if(choice == "seek"){
			cc.Seek();
		}
		else if(choice == "load"){
			cc.Load();
		}
		else if(choice == "save"){
			cc.Save();
		}
		else if(choice == "list"){
			cc.List();
		}
		else{
			std::cout << "other choice\n";
		}
		ShowMenu();
		choice = GetString();
	}
	std::cout << "Bye!\n";
	return 0;
}

void ShowMenu(){
	std::cout << "add del seek update list load save quit\n";
	std::cout << "command: ";
}

static std::string GetString(){
	// cin.clear() then return what you input (one line)
	std::string str;
	//getline(std::cin, str);
	std::cin >> str;    // get one word
	std::cin.get(); // eat a space
	std::cin.clear();   // for EOF
	return str;
}
