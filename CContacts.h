#ifndef CCONTACT_H_
#define CCONTACT_H_
#include <map>
#include <string>
#include "CData.h"

class CContacts {
private:
	const int NAMELIM{30};
	// name + (CData)info
	std::map<const std::string, const CData> m_contacts;
public: // public Clear() for testing.
	void Clear();
public:
	// ctor(s)
	CContacts();
	CContacts(const string& name);
	// init
	void init(const string& name = "nobody");
	// Add a contact
	void Add();	// interactive
	void Add(const string& name, CData& data);
	// Delete someone
	void Del();
	void Del(const string& name);
	// Modify someone's info
	void Mod();
	void Mod(const string& name);
	// Search someone
	void Search();
	bool Search(const string& name);
	// List all contacts and info
	void List() const;
	// Load from a file
	void Load();
	void LoadFrom(const char * fileName);
	// Save as a file
	void Save();
	void SaveAs(const char * fileName);
};
#endif // CCONTACT_H_
