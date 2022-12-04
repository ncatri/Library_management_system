#ifndef EXTRACT_DATA
#	define EXTRACT_DATA

#	include <iostream>
#	include <fstream>
#	include <vector>
#	include "book.hpp"
#	include "user.hpp"

#	include <sstream>

class FileOperator {

	public:
		FileOperator(std::string book_file_path, std::string user_file_path);
		~FileOperator();

		void	displayFile();
		void	appendFile(std::string const& line);

		std::vector<Book>	loadBooks();
		std::vector<User>	loadUsers();

		template <typename T>
		void	saveObjects(std::vector<T> objs, std::string file_to_write) {
			std::ofstream saveFile(file_to_write);
			if (saveFile.is_open()) {
				typedef typename std::vector<T>::iterator iterator;
				for (iterator it = objs.begin(); it != objs.end(); ++it)
					saveFile << *it << '\n';
			}
		};

	private:
		std::vector<std::string> 	fromLinesToAttributes(std::string file_name);
		std::vector<Book>			fromAttributesToBooks(std::vector<std::string> strings);
		std::vector<User>			fromAttributesToUsers(std::vector<std::string> strings);

		const std::string		_books_file_name;
		const std::string		_users_file_name;

};

std::vector<std::string> split(std::string str, char sep); 

#endif
