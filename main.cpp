#include <iostream>
#include "extract_data.hpp"
#include "model.hpp"

int main(int argc, char** argv) {

	if (argc != 2){
		std::cerr << "Need one filename" << std::endl;
		return (1);
	}

	FileOperator fileOperator(argv[1]);

	std::vector<Book> books = fileOperator.loadBooks();

	typedef std::vector<Book>::iterator book_iterator;
	for (book_iterator bi = books.begin(); bi != books.end(); ++bi)
		std::cout << *bi << std::endl;
}
