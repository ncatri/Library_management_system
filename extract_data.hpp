#ifndef EXTRACT_DATA
#	define EXTRACT_DATA

#	include <iostream>
#	include <fstream>
#	include <vector>
#	include "model.hpp"

#	include <sstream>

class FileOperator {

	public:
		FileOperator(std::string book_file_path, std::string user_file_path);
		~FileOperator();

		void	displayFile();
		void	appendFile(std::string const& line);

		std::vector<Book>	loadBooks();
		std::vector<User>	loadUsers();

		void	saveBooks(std::vector<Book>, std::string books_file_write);
		void	saveUsers(std::vector<User>, std::string users_file_write);

	private:
		std::vector<std::string> 	fromLinesToAttributes(std::string file_name);
		std::vector<Book>			fromAttributesToBooks(std::vector<std::string> strings);
		std::vector<User>			fromAttributesToUsers(std::vector<std::string> strings);

		const std::string		_books_file_name;
		const std::string		_users_file_name;

};

std::vector<std::string> split(std::string str, char sep); 

#endif
