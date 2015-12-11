#include <iostream>
#include <fstream>
#include "CContacts.h"
// ctors
CContacts::CContacts(){
	init();
}

CContacts::CContacts(const std::string& name, const std::string& email){
	init(name, email);
}
// init
void CContacts::init(const std::string& name, const std::string& email){
	Update(name, email);
}
// 
static std::string GetString(){
	// cin.clear() then return what you input (one line)
	std::string str;
	getline(std::cin, str);
	std::cin.clear();   // for EOF
	return str;
}
// methods
// Add one with interaction
void CContacts::Add(){
	std::cout << "Add this person: ";
	std::string name = GetString();
	if(name.length() != 0){
		std::cout << "His/Her Email Address is: ";
		std::string email = GetString();
		Update(name, email);	// call Update()
	}
}
// Delete one with interaction
void CContacts::Del(){
	std::cout << "Delete this person: ";
	std::string name = GetString();
	if(Seek(name)){
		m_contacts.erase(name);
		std::cout << "\"" << name << "\" DELETED.\n";
	}
	else{
		std::cout << "\"" << name << "\" NOT found.\n";
	}
}
// Update with interaction
void CContacts::Update(){
	std::cout << "Update this person's infomation: ";
	std::string name = GetString();
	// Seek the name
	if(Seek(name)){
		std::string email = GetString();
		Update(name, email);;	// call Mod() if exists
	}
	else{	// ask for creating if not exists
		std::cout << name << "NOT found.\n"
			<< "Would you like to CREATE one? [yes/no]";
			std::string choice = GetString();
			if(choice == "yes" || choice == "y"){
				std::cout << "His/Her Email Address is: ";
				std::string email = GetString();
				Update(name, email);
			}
			else{
				std::cout << "I think you said \"no\".\n";
			}
	}
}
// Update all data
void CContacts::Update(const std::string& name, const std::string& email){
	if(name.length() != 0){
		m_contacts.insert(make_pair(name, email));
	}
}
// Seek a name with interaction
void CContacts::Seek(){
	std::cout << "Seek this person: ";
	std::string name = GetString();
	if(Seek(name)){
		std::cout << "\"" << name << "\" found\n";
	}
	else{
		std::cout << "\"" << name <<"\" NOT found\n";
	}
}
// Seek a name, return true or false
bool CContacts::Seek(const std::string& name){
	// return True if name exists
	if(m_contacts.find(name) != m_contacts.end()){
		return true;
	}
	else return false;
}

void CContacts::List() const {
	std::cout << "    list\n"
		<< "--------\n";
	for(auto iter : m_contacts){
		std::cout << iter.first << ", " << iter.second << "\n";
	}
	std::cout << "--------\n"
		<< "     end\n";
}

void CContacts::Load(){
	//std::cout << "Load()\n";
	const std::string firstLine = "{";
	std::ifstream fin;
	std::string fileName = GetString();
	
	fin.open(fileName.c_str());
	if(fin.is_open()){
		std::cout << "success to open " << fileName << "\n";
		std::string readLine;
		getline(fin, readLine);
		// simple check,
		if(readLine != firstLine){
			std::cout << fileName << " is not a file created by this program.\n";
		}
		else{
	        // read and insert
	        std::string firstWord, secondWord;
			do {
			// format sample:
			// {
			// "firstWord":"secondWord",
			// "loopFirstWord":"secondWord",
			// "eof":"eof"
			// }
				fin.get(); // 1 --> "
				getline(fin, firstWord, '\"');  // 2 --> firstWord"
				std::cout << " name: " << firstWord << "\n";
				fin.get();  // 3 --> :
				fin.get();	// 4 --> "
				getline(fin, secondWord, '\"'); //  5 --> secondWord"
				std::cout << "email: " << secondWord << "\n";
				fin.get();	// 6 --> ,
				fin.get();  // 7 --> '\n'
				// stop at my eof tag "eof":"eof"
				if(firstWord != "eof" && secondWord != "eof"){
					m_contacts.insert(make_pair(firstWord, secondWord));
				}
				else{
					fin.close();
					break;
				}
			}while(fin.good());
			fin.clear();
			fin.close();
		}
	}
	else{
		std::cout << "fail to open " << fileName << "\n";
	}
}

void CContacts::Save(){
	//
	std::cout << "Save()\n";
	std::fstream fio;
	std::string fileName = GetString();
	const std::string firstLine = "{\n";    // {
	const std::string lastLine = "\n}"; // }
	const std::string eofTag = "\"eof\":\"eof\"";   // "eof":"eof"
	const std::string sep = ":";
	const std::string comma = ",";
	const std::string enter = "\n";
	std::cout << "filename: ";
	fio.open(fileName.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::app);
	if(fio.is_open()){
		std::cout << "sucess to open " << fileName << "\n";
		// format sample:
		// {
		// "firstWord":"secondWord",
		// "loopFirstWord":"secondWord",
		// "eof":"eof"
		// }
		fio << firstLine;
		std::map<std::string, std::string>::iterator iter;
		for(iter = m_contacts.begin(); iter != m_contacts.end(); ++iter){
			fio << "\"" << iter->first << "\"" << sep
				<< "\"" << iter->second << "\"";
			fio << comma << enter;
		}
		fio << eofTag;
		fio << lastLine;
	}
	else{
		std::cout << "fail to open " << fileName << "\n";
	}
	fio.clear();
	fio.close();
}
