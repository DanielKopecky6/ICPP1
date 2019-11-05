#include "Person.h"

Entity::Person::Person(int aId, std::string aName, std::string aPhone)
{
	id = aId;
	name = aName;
	phone = aPhone;
}
int Entity::Person::getId() const
{
	return id;
}
std::string Entity::Person::getName() const
{
	return name;
}
std::string Entity::Person::getPhone() const
{
	return phone;
}
void Entity::Person::setId(int aId)
{
	id = aId;
}
void Entity::Person::setName(std::string aName)
{
	name = aName;
}
void Entity::Person::setPhone(std::string aPhone)
{
	phone = aPhone;
}


