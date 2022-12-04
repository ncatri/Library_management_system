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

		template <typename T>
		void	deleteObj(typename std::vector<T>& vec, int id){
			typedef typename std::vector<T>::iterator iterator;
			iterator it = vec.begin();
			for (; it != vec.end(); ++it) {
				if (it->getId() == id)
					vec.erase(it);
			}
			if (it == vec.end())
				throw ObjectNotFoundException();
		};

		class ObjectNotFoundException : public std::exception {
			public:
				const char *what() const throw();
		};

	private:

		FileOperator		_fileOperator;
		std::vector<Book>	_books;
		std::vector<User>	_users;
};

#endif
