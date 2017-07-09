// designPatternFlyweight.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <boost/flyweight.hpp>
#include <string>
#include <vector>
#include <utility>

using namespace boost::flyweights;

class Person
{
public:
	Person(int id, std::string city, std::string country)
		: id_{ id }, city_{ std::move(city) }, country_{ std::move(country) } {}
	std::string getCity() const { return city_; }
	std::string getCountry() const { return country_; }
private:
	int id_;
	flyweight<std::string> city_;
	flyweight<std::string> country_;
};

std::ostream &operator<<(std::ostream& str, const Person& person)
{
	return str << person.getCity() << " " << person.getCountry() << "\n";
}

int main()
{
	std::vector<Person> persons;
	for (int i = 0; i < 1000; ++i)
	{
		persons.push_back({ i, "Berlin", "Germany" });
		persons.push_back({ i + 1000, "Warsaw", "Poland" });
	}
	for (const auto& itr : persons)
		std::cout << itr << std::endl;
}
