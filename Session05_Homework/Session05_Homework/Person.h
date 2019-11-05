#ifndef PERSON_H
#define PERSON_H
#include <string>
namespace Entity {

	struct Person
	{
	private:
		int id;
		std::string name;
		std::string phone;
	public:
		Person() {};
		Person(int aId, std::string aName, std::string aPhone);
		~Person() {};
		std::string getName()const;
		std::string getPhone()const;
		int getId()const;
		void setName(std::string aName);
		void setPhone(std::string aPhone);
		void setId(int aId);

	};
}
#endif // PERSON_H
