// test CData
#include <iostream>
#include "CData.h"
int main(){
	typedef CData Data;
	Data test;
	test.Show();
	test.Modify();
	test.Show();
	test.Save();
	test.Load();
	std::cout << "Bye!\n";
	return 0;
}
