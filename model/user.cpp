#include "user.hpp"

User::User() {}

User::~User() {}

User::User(int id, std::string name, std::string surname) : _id(id), _name(name), _surname(surname) {}

/*
User::User(User& src) {
	*this = src;
}

User&	User::operator=(User& rhs) {
	if (this != &rhs){
		this->_id = rhs._id;
		this->_name = rhs._name;
		this->_surname = rhs._surname;
	}
	return (*this);
}
*/
int			User::getId() const {return (this->_id); }

std::string	User::getName() const {return (this->_name); }

std::string	User::getSurname() const {return (this->_surname); }

std::ostream& operator<<( std::ostream& o, User& rhs) {
	o << rhs.getId() << ";" << rhs.getName() << ";" << rhs.getSurname();
	return (o);
}

