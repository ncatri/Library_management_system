#include <iostream>
#include "extract_data.hpp"

int main(int argc, char** argv) {

	if (argc != 2){
		std::cerr << "Need one filename" << std::endl;
		return (1);
	}

	FileOperator fileOperator(argv[1]);
	fileOperator.DisplayFile();


}
