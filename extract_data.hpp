#ifndef EXTRACT_DATA
#	define EXTRACT_DATA

#	include <iostream>
#	include <fstream>
#	include <vector>
#	include "model.hpp"

#	include <sstream>

class FileOperator {

	public:
		FileOperator(std::string file_path);
		~FileOperator();

		void	displayFile();
		void	appendFile(std::string const& line);

		std::vector<Book>	loadBooks();
		std::vector<User>	loadUsers();



	private:
		std::vector<std::string> 	fromLinesToAttributes();
		std::vector<Book>			fromAttributesToObjects(std::vector<std::string> strings);

		const std::string		_file_name;

};

std::vector<std::string> split(std::string str, char sep); 

#endif
