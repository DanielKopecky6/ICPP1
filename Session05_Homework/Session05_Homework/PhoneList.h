#ifndef PHONELIST_H
#define PHONELIST_H
#include "Person.h"


namespace Model {
	struct List {
	public:
		List* next;
		Entity::Person person;
		List(List* aNext, Entity::Person aPerson);
		~List() {};
	};

	struct PhoneList {
	private:
		List* lastRecord;
		int numberOfRecords;
	public:
		PhoneList();
		~PhoneList() {};
		void addPerson(Entity::Person p);
		std::string  findPhone(std::string aName)const;
		std::string findPhone(int aId) const;

	};

}


#endif // PHONELIST_H

