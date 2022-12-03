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

void	FileOperator::appendFile(std::string const& line) {
	std::ofstream file;
	file.open(this->_file_name, std::ios::app);
	file << line << '\n';
}
