#include <iostream>
#include <fstream>  // read / write file
#include <cstring>
#include <utility>  // std::pair
#include "CContacts.h"// Input a name

// typedef
typedef std::pair<const string&, CData> Pair;	// name + Info
// Class CContacts
// ctor(s)
CContacts::CContacts(){
	init();
}

CContacts::CContacts(const string& name) {
	init(name);
}

// init CContacts
void CContacts::init(const string& name){
	if(strlen(name) != 0){
		pair<std::string, CData>;
	}
	else{
		std::cout << "do nothing.\n";
	}
}

// Add a person
void CContacts::Add(){
	CData data;
	std::cout << "Add this guy to my contact book: ";
	char name[NAMELIM];
	std::cin.get(name, NAMELIM);
	if(strlen(name) != 0){
		data.Modify();
		Add(name, data);
	}
	else{
		std::cout << "No one added\n";
	}
}

void CContacts::Add(const string& name, CData& data) {
		Pair pairValue(name, data);
		m_contacts.insert(pairValue);
		std::cout << name << " added.\n";
}

// Delete a person
void CContacts::Del(){
	std::cout << "I want to delete: ";
	char name[NAMELIM];
	std::cin.get(name, NAMELIM);
	if(strlen(name) != 0){
		Del(name);
	}
}

void CContacts::Del(const string& name) {
	if(Search(name) == true){
		m_contacts.erase(name);
		std::cout << name << " deleted.\n";
	}
}

// Modify a person's info
void CContacts::Mod(){
	CData data;
	std::cout << "I want to modify: ";
	char name[NAMELIM];
	getline(name, NAMELIM);
	if(strlen(name) != 0){
	// name is not null AND name exists
		Mod(name);
	}
	else{
		std::cout << "Nothing changes.\n";
	}
}

void CContacts::Mod(const string& name) {
	if(Search(name) == true){
		CData tmpData;
		tmpData.Modify();
		m_contacts[name] = tmpData;
		std::cout << name << " modified.\n";
		m_contacts[name].Show();
	}
}

// Search a person
void CContacts::Search(){
	std::cout << "I want to search: ";
	char name[NAMELIM];
	getline(name, NAMELIM);
	Search(name);
}

bool CContacts::Search(const string& name){
	if(m_contacts.find(name) != m_contacts.end()){
		std::cout << name << " found.\n";
		return true;
	}
	else
	{
		std::cout << name << " is Not in your contact book.\n";
		return false;
	}
}

// List all contacts and info
void CContacts::List() const {
	std::cout << "-- List all contacts and info --\n";
	const int width = 15;
	for(auto contact : m_contacts){
		std::cout.width(width);
		std::cout << "Name: " << contact.first << "\n";	// name
		contact.second.Show();	// data in CData
	}
	std::cout << "-- End of List --\n";
}

// Load from a file
void CContacts::Load(){
	std::cout << "Load from (filename): ";
	char name[NAMELIM];
	getline(name, NAMELIM);
	LoadFrom(fileName.c_str());
}

void CContacts::LoadFrom(const string& fileName){
	std::ifstream fin(fileName);
	if(fin.is_open()){
		std::cout << fileName << " exists.\n"
				<< "Reading from " << fileName << "\n";
//		pair<string&, CData>::iterator it;
//		pair<string&, CData> data;
//		Clear();
//		for(it = m_contacts.begin(); it != m_contacts.end(); ++it){
//			fin.read((string&)data, sizeof(pair<string&, CData));
//			m_contacts.insert(data);
//		}
		std::cout << "Success to read " << fileName << "\n";
		fin.close();
	}
	else{
		std::cout << "fail to open " << fileName << "\n";
		fin.clear();
	}
	fin.close();
}

// Save as a file
void CContacts::Save(){
	std::cout << "Save as (filename): ";
	char name[NAMELIM];
	getline(name, NAMELIM);
	SaveAs(fileName.c_str());
}

void CContacts::SaveAs(const string& fileName){
	std::fstream fio;
	// open fileName with reading|binary mode
	fio.open(fileName, std::ios_base::in|std::ios_base::binary);
	if(fio.is_open()){
		std::cout << fileName << " exists.\n";
		fio.close();
	}
	else{
		fio.clear();
		std::cout << fileName << " does NOT exists.\n"
				<< "Would you like to create it? [yes/no]:";
		string& choice;
		getline(std::cin, choice);
		if(choice == "yes" || choice == "y"){
			// open fileName with writing|binary mode
			fio.open(fileName, std::ios_base::out|std::ios_base::binary);
			if(fio.is_open()){
				std::cout << "Success to open " << fileName << "\n"
						<< "Writing to " << fileName << "\n";
				std::map<string&, CData>::iterator it;
				Pair data;
				size_t sizeOfDataCStr;
				size_t sizeOfDataSecond_phoneNum;
				size_t sizeOfDataSecond_email;
				for(it = m_contacts.begin(); it != m_contacts.end(); ++it){
					// too bad
					sizeOfDataCStr = sizeof data.first.c_str();
					sizeOfDataSecond_phoneNum = sizeof data.second.PhoneNum().c_str();
					sizeOfDataSecond_email = sizeof data.second.Email().c_str();
					
					//fio.write((string&)sizeOfDataCStr, sizeof size_t);
					
					//fio.write((string&)data.first.c_str(), sizeOfDataCStr);
					
					//fio.write((string&)data.second.PhoneNum().c_str(), sizeOfDataSecond_phoneNum);
					
					//fio.write((string&)data.second.Email().c_str(), sizeOfDataSecond_email);
				}
				std::cout << "Success to save as " << fileName << "\n";
				fio.close();
			}
		}
		else{
			std::cout << "did nothing.\n";
		}
		fio.close();
	}
}

void CContacts::Clear(){
	std::cout << "under construction ...\n";
//	std::map<string&, CData>::iterator it;
//	for(it = m_contacts.begin(); it != m_contacts.end(); /* */){
//		m_contacts.erase(it);
//		it++;
//	}
}
