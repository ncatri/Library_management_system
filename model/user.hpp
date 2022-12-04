#ifndef USER_HPP
#	define USER_HPP

#	include <iostream>


class User {
	public:
		User();
		~User();
		User(int id, std::string name, std::string surname);
		
		int			getId() const;
		std::string getName() const;
		std::string getSurname() const;

	private:
		int 		_id;
		std::string	_name;
		std::string	_surname;
};

std::ostream& operator<<( std::ostream& o, User& rhs);

#endif
