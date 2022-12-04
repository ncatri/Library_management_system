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

		template <typename T>
		int		getIdMax(std::vector<T> vec) {
			int idMax = 0;
			typedef typename std::vector<T>::iterator iterator;
			for (iterator it = vec.begin(); it != vec.end(); ++it) {
				if (it->getId() > idMax)
					idMax = it->getId();
			};
			return (idMax);
		};

	private:

		FileOperator		_fileOperator;
		std::vector<Book>	_books;
		std::vector<User>	_users;
};

#endif
