#ifndef EXTRACT_DATA
#	define EXTRACT_DATA

#	include <iostream>
#	include <fstream>

class FileOperator {

	public:
		FileOperator(std::string file_path);
		~FileOperator();

		void	DisplayFile();

	private:
		std::fstream	_file;
		std::string		_file_name;

};


#endif
