#include <iostream>
#include "extract_data.hpp"
#include "model.hpp"

int main(int argc, char** argv) {

	if (argc != 3){
		std::cerr << "Usage: ./run livres.db abonnes.db" << std::endl;
		return (1);
	}

	FileOperator fileOperator(argv[1], argv[2]);

	std::vector<Book> books = fileOperator.loadBooks();
	std::vector<User> users = fileOperator.loadUsers();

	typedef std::vector<Book>::iterator book_iterator;
	for (book_iterator bi = books.begin(); bi != books.end(); ++bi)
		std::cout << *bi << std::endl;

	typedef std::vector<User>::iterator user_iterator;
	for (user_iterator ui = users.begin(); ui != users.end(); ++ui)
		std::cout << *ui << std::endl;
}
