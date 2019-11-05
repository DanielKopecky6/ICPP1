#include "PhoneList.h"

Model::List::List(List * aNext, Entity::Person aPerson)
{
	next = aNext;
	person = aPerson;

}

Model::PhoneList::PhoneList()
{
	numberOfRecords = 0;
	lastRecord = nullptr;
}

void Model::PhoneList::addPerson(Entity::Person p)
{
	List* newPerson = new List(lastRecord, p);
	newPerson->person.setId(p.getId());
	newPerson->person.setName(p.getName());
	newPerson->person.setPhone(p.getPhone());
	lastRecord = newPerson;
}

std::string Model::PhoneList::findPhone(std::string aName) const
{
	return std::string();
}

std::string Model::PhoneList::findPhone(int aId) const
{
	return std::string();
}










std::string Model::Phonebook::findTelNumber(int id) const
{
	if (id < 0) {
		throw std::invalid_argument("Id must be bigger then or equal to zero!");
	}
	if (size > 0) {
		LinkListElement* temp = first;
		while (temp->next != nullptr) {
			if (temp->data.getId() == id) {
				return temp->data.getTelNumber();
			}
			temp = temp->next;
		}
	}
	throw ElementDoesNotExist("Finding tel. number does not exist");
}

std::string Model::Phonebook::findTelNumber(std::string name) const
{
	if (name.length() == 0) {
		throw std::invalid_argument("String in parameter is not correct!");
	}
	if (size > 0) {
		LinkListElement* temp = first;
		while (temp->next != nullptr) {
			if (temp->data.getName().compare(name) == 0) {
				return temp->data.getTelNumber();
			}
			temp = temp->next;
		}
	}
	throw ElementDoesNotExist("Finding tel. number does not exist");
}

Model::LinkListElement::LinkListElement(LinkListElement* aNext, Entity::Person aData) : next(aNext), data(aData)
{
}

Model::LinkListElement::~LinkListElement()
{
}

ElementDoesNotExist::ElementDoesNotExist(const std::string& aMess) :mess(aMess)
{
}

const char* ElementDoesNotExist::what() const noexcept
{
	return mess.c_str();
}
