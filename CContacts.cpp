#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <pair>
#include "CContacts.H"
// CContacts::m_CInfo
CContacts::m_CInfo::m_CInf(std::string phoneNum, std::string email){
	init();
}
// init
CContact::m_CInfo::init(phoneNum = '-', std::string email = "-"){
	m_phoneNum = phoneNum;
	m_email = email;
}

// Class CContacts
// a typedef for data
typedef CContacts::m_CInfo Info;
typedef std::pair<std::string& name, Info& info>) Pair;
CContact::CContact(){
	init();
}

CContact::CContacts(std::string& name, std::string& phoneNum, std::string& email) {
	init(name, phoneNum, email);
}
// init
void CContacts::init(std::string& name, std::string& phoneNum, std::string& email){
	m_mAddrBook = map(name, phoneNum, email);
// Add a person
void CContacts::Add(std::string& name, std::string& phoneNum, std::string& email) {
	tmpInfo = Info(phoneNum, email);
	m_contacts.insert(Pair(name, tmpInfo);
}

void CContacts::Del(std::string name) {
	m_contact.erase(name.c_str);
}

void Modify(std::string& name, std::string& phoneNum) {
	m_contact[name.c_str] = phoneNum;
}

void Search(std::string& name){
	m_contact.find(name.c_str);
}

