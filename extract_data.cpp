#include "extract_data.hpp"

FileOperator::FileOperator( std::string file_path): _file_name(file_path) {}

FileOperator::~FileOperator() {}

void	FileOperator::displayFile() {
	std::string line;
	std::ifstream file(this->_file_name);

	if (file.is_open()) {
		while (getline(file, line))
			std::cout << line << std::endl;
	}
	else
		std::cout << "can't open file " << this->_file_name << "!" << std::endl;
}

std::vector<std::string> FileOperator::getLines() {
	std::ifstream file(this->_file_name);
	std::string line;
	std::vector<std::string> result;
	if (file.is_open()) {
		while (getline(file, line))
			result.push_back(line);
	}
	return (result);
}

// should I output directly Book and User object?
std::vector<Book>	getBooks(std::vector<std::string> strings) {
	std::vector<Book> books;

	std::vector<std::string> attributes;
	
	typedef std::vector<std::string>::iterator iterator;
	for (iterator it; it != strings.end(); ++it) {
		attributes = split(*it, ';');
		books.push_back(Book(attributes[0], attributes[1], attributes[2], \
					attributes[3], attributes[4], attributes[5]));
	}

	return (books);
}

std::vector<std::string> split(std::string str, char sep) {
	std::vector<std::string> result;
	std::stringstream sstr(str);
	std::string	fragment;

	while (std::getline(sstr, fragment, sep))
			result.push_back(fragment);
	return (result);	
}


void	FileOperator::appendFile(std::string const& line) {
	std::ofstream file;
	file.open(this->_file_name, std::ios::app);
	file << line << '\n';
}
