#include <iostream>
#include "view.hpp"
#include "model.hpp"
#include "controller.hpp"

void	testDataLoading(std::string booksFile, std::string usersFile);
void	testView();

int main(int argc, char** argv) {

	if (argc != 3 || std::string("livres.db").compare(argv[1]) || std::string("abonnes.db").compare(argv[2])){
		std::cerr << "Usage: ./run livres.db abonnes.db" << std::endl;
		return (1);
	}

	Model model(argv[1], argv[2]);
	View console;

	Controller	library(model, console);
	library.showdata();
//	library.run();

//	testDataLoading(argv[1], argv[2]);
//	testView();
};

void testDataLoading(std::string booksFile, std::string usersFile) {

	FileOperator fileOperator(booksFile, usersFile);
	std::vector<Book> books = fileOperator.loadBooks();
	std::vector<User> users = fileOperator.loadUsers();


	fileOperator.saveObjects<Book>(books, booksFile);
	books[2].setBorrowerId(44);
	fileOperator.saveObjects<Book>(books, booksFile);

	fileOperator.saveObjects<User>(users, usersFile);
}

void	testView() {
	View console;
	console.display("here we are.");
	int ans = console.prompt_int("Please enter an int: ");
	console.display("You entered " + std::to_string(ans));

}
