#include "model.hpp"

Book::Book(): 
	_id(), _title1(), _title2(), _author1(), _author2(), _borrowerId() {}

Book::~Book() {}

Book::Book(int id, std::string title1, std::string title2,\
				std::string author1, std::string author2, int borrowerId) :
	_id(id), _title1(title1), _title2(title2), _author1(author1), _author2(author2), _borrowerId(borrowerId) {}

int	Book::getId() const { return (this->_id); }
std::string	Book::getTitle1() const {
	return (this->_title1);
}
std::string	Book::getTitle2() const {
	return (this->_title2);
}
std::string	Book::getAuthor1() const {
	return (this->_author1);
}
std::string	Book::getAuthor2() const {
	return (this->_author2);
}
int	Book::getBorrowerId() const { return (this->_borrowerId); }

std::ostream&	operator<<( std::ostream& o, Book& rhs ) {
	// overload used to write in database
	o << rhs.getId() << ";";
	o << rhs.getTitle1() << ";" ;
	o << rhs.getTitle2() << ";" ;
	o << rhs.getAuthor1() << ";" ;
	o << rhs.getAuthor2() << ";" ;
	o << rhs.getBorrowerId() << ";" ;
	return (o);
}

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
