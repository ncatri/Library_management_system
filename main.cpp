#include <iostream>
#include "extract_data.hpp"
#include "model.hpp"

void	testDataLoading(std::string booksFile, std::string usersFile);

int main(int argc, char** argv) {

	if (argc != 3){
		std::cerr << "Usage: ./run livres.db abonnes.db" << std::endl;
		return (1);
	}

	testDataLoading(argv[1], argv[2]);
};

void testDataLoading(std::string booksFile, std::string usersFile) {

	FileOperator fileOperator(booksFile, usersFile);
	std::vector<Book> books = fileOperator.loadBooks();
	std::vector<User> users = fileOperator.loadUsers();

	typedef std::vector<Book>::iterator book_iterator;
	for (book_iterator bi = books.begin(); bi != books.end(); ++bi) {
		if (bi->getId() == 3)
			bi->setBorrowerId(42);
	}

/*
	typedef std::vector<User>::iterator user_iterator;
	for (user_iterator ui = users.begin(); ui != users.end(); ++ui)
		std::cout << *ui << std::endl;
*/
	fileOperator.saveBooks(books, booksFile);
	books[2].setBorrowerId(0);
	fileOperator.saveBooks(books, booksFile);
}
