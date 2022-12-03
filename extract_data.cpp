#include "extract_data.hpp"

FileOperator::FileOperator( std::string file_path): _file_name(file_path) {
	this->_file.open(file_path);
}

FileOperator::~FileOperator() {
	this->_file.close();
}

void	FileOperator::DisplayFile() {
	std::string line;
	if (this->_file.is_open()) {
		while (getline(this->_file, line))
			std::cout << line << std::endl;
	}
	else
		std::cout << "can't open file " << this->_file_name << "!" << std::endl;
}
