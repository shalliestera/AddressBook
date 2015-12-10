#ifndef CCONTACT_H_
#define CCONTACT_H_
#include <map>
#include <string>
class CContact {
privite:
	class m_CInfo {
		private:
			std::string m_phoneNum;
			std::string m_email;
		public:
			m_CInfo(std::string phoneNum = '-', std::string email = '-') = default;
			init();
	};
	// name + info
	map<std::string, m_Cinfo info> m_contact;
public:
	CAddrBook();
	CAddrBook(std::string name, m_CInfo info);
	// init
	void init(std::string name = "nobody", std::string phoneNum = "-", std::string::email = "-"); 	
	// Add a contact
	void Add(std::string name, std::string phoneNum = "-", std::string email = "-");	
	// Delete someone
	void Del(std::string name);
	// Modify someone's info
	void Modify(std::string name);
	// Search someone
	void Search(std::string name);
	// List all contacts and info
	void List() const;
};
#endif // CCONTACT_H_
