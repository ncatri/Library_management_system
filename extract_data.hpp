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

		std::vector<std::string> getLines();
		std::vector<std::string> parseLine(std::string line, int number_of_fields, char separator);


	private:
		const std::string		_file_name;

};

std::vector<std::string> split(std::string str, char sep); 


#endif
