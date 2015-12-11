#ifndef CContacts
#define CContacts

class CContacts {
private:
	// map<std::string, std::string>
	map<std::string, std::string> m_contacts;
public:
	CContacts();
	CContacts(std::string, std::string);
	Init();
	// methods
	// add del modify search
	// load / save
	void Add();
	void Del();
	void Mod();
	void Seek();
	void Load();
	void Save();
};