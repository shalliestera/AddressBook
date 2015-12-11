#ifndef CDATA_H_
#define CDATA_H_
#include <string>
// class CData here
class CData {
	private:
		// You can add more data here;
		// includes phoneNum && email
		std::string m_sPhoneNum;
		std::string m_sEmail;
	public:
		// ctors
		CData();
		CData(const std::string& phoneNum, const std::string& email);
		// init CData
		void init(const std::string& phoneNum = "-", const std::string& email = "-");
		// modify
		void ModPhoneNum(const std::string& phoneNum);
		void ModEmail(const std::string& email);
		// modify + prompt
		void Modify();
		// show all data
		void Show() const;
		// file operations
		// Save
		void Save();
		void SaveAs(std::fstream& fio, const char* fileName);
		// Load
		void Load();
		void LoadFrom(std::ifstream& fin, const char* fileName);
		// inline methods, return const data
		const std::string& PhoneNum() const {return m_sPhoneNum;}
		const std::string& Email() const {return m_sEmail;}
};

#endif // CDATA_H_
