#ifndef CCONTACTS_H_
#define CCONTACTS_H_
#include <map>
#include <string>

class CContacts {
private:
	// map<std::string, std::string>
	std::map<std::string, std::string> m_contacts;
	unsigned long count;
public:
	// ctors 'n' init
	CContacts();
	CContacts(const std::string& name, const std::string& email);
	void init(const std::string& name = "", const std::string& email = "");
	// methods
	// add del modify seek load / save
	void Add();
	void Del();
	void Update();
	void Update(const std::string& name, const std::string& email);
	void Seek();
	bool Seek(const std::string& name);
	void List() const;
	void Load();
	void Save();
};

#endif // CCONTACTS_H_
