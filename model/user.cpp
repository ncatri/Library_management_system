#include "user.hpp"

User::User() {}

User::~User() {}

User::User(int id, std::string name, std::string surname) : _id(id), _name(name), _surname(surname) {}

int			User::getId() const {return (this->_id); }

std::string	User::getName() const {return (this->_name); }

std::string	User::getSurname() const {return (this->_surname); }

std::ostream& operator<<( std::ostream& o, User& rhs) {
	o << rhs.getId() << ";" << rhs.getName() << ";" << rhs.getSurname();
	return (o);
}

