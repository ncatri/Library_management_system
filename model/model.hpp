#ifndef MODEL_HPP
#	define MODEL_HPP

#	include <iostream>
#	include "book.hpp"
#	include "user.hpp"
#	include "extract_data.hpp"

class Model {

	public:
		Model(std::string book_file_path, std::string user_file_path);
		~Model();

		std::vector<Book>&	getBooks();
		std::vector<User>&	getUsers();

	private:

		FileOperator		_fileOperator;
		std::vector<Book>	_books;
		std::vector<User>	_users;

};

#endif
