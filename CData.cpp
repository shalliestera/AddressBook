#include <iostream>
#include <fstream>
#include <string>
#include "CData.h"
// class CData
// ctor(s)
std::string GetName(){
	std::string name;
	getline(std::cin, name);
	return name;
}
CData::CData(){
	init();
}

CData::CData(const std::string& phoneNum, const std::string& email){
	init(phoneNum, email);
}

// init CData
void CData::init(const std::string& phoneNum, const std::string& email){
	m_sPhoneNum = phoneNum;
	m_sEmail = email;
}

// modify CData
// inputting nullstring will not change the data
void CData::ModPhoneNum(const std::string& phoneNum){
	if(phoneNum.length() != 0){
		m_sPhoneNum = phoneNum;
		std::cout << "New phone number is " << PhoneNum()
				<< "\n";
	}
	else{
		std::cout << "Phone number " << PhoneNum()
				<< " has not been changed.\n";
	}
}

void CData::ModEmail(const std::string& email){
	if(email.length() != 0){
		m_sEmail = email;
		std::cout << "New email address is " << Email()
				<< "\n";
	}
	else{
		std::cout << "Email address "<< Email()
				<< " has not been changed.\n";
	}
}

void CData::Modify(){
	// enter what you want to modify
	std::string phoneNum;
	std::string email;
	std::cout << "Input a phone number and press [Enter]: ";
	getline(std::cin, phoneNum);
	ModPhoneNum(phoneNum);
	
	std::cout << "Input an email address and press [Enter]: ";
	getline(std::cin, email);
	ModEmail(email);
}

// show all data
void CData::Show() const {
	const int width = 15;
	std::cout.width(width);
	std::cout << "PhoneNum: " << PhoneNum() << "\t";
	std::cout.width(width);
	std::cout << "Email: " << Email() << "\n";
}

// file operations
void CData::Save(){
	std::cout << "Save as this file: ";
	std::string name = GetName();
	std::fstream fio;
	SaveAs(fio, name.c_str());
	fio.close();
}

void CData::SaveAs(std::fstream& fio, const char* fileName){
	std::cout << "Save As " << fileName << "...\n";
	fio.open(fileName, std::ios_base::in|std::ios_base::binary);
	if(fio.is_open()){
		std::cout << "Success to open " << fileName << "\n";
		fio.write("success to write.", 30);
	}
	else{
		std::cout << "Fail to open " << fileName << "\n";
	}
	fio.close();
}

void CData::Load(){
	std::cout << "Load from this file: ";
	std::string name = GetName();
	std::ifstream fin;
	LoadFrom(fin, name.c_str());
	fin.close();
}

void CData::LoadFrom(std::ifstream& fin, const char* fileName){
	std::cout << "Load from " << fileName << "\n";
	fin.open(fileName);
	if(fin.is_open()){
		std::cout << "Success to open " << fileName << "\n";
	}
	else{
		std::cout << "Fail to open " << fileName << "\n";
	}
	fin.close();
}
