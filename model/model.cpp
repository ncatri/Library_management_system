#include "model.hpp"

Model::Model(std::string book_file_path, std::string user_file_path):
	_fileOperator(book_file_path, user_file_path) {

	this->_books = this->_fileOperator.loadBooks();
	this->_users = this->_fileOperator.loadUsers();
}

Model::~Model() {}

std::vector<Book>&	Model::getBooks() { return (this->_books); }

std::vector<User>&	Model::getUsers() { return (this->_users); }

FileOperator		Model::getFileOperator() const { return (this->_fileOperator); }

const char	*Model::ObjectNotFoundException::what() const throw() {
	return ("Object not found (user or book)");
}

const char	*Model::BookUnavailableException::what() const throw() {
	return ("Book is unavailable");
}

void	Model::addUser(User& newUser) { this->_users.push_back(newUser); }

void	Model::addBook(Book& newBook) { this->_books.push_back(newBook); }

void	Model::rentBook(int userId, int bookId) {
	typedef typename std::vector<User>::iterator it_user;
	it_user it = this->_users.begin();
	bool is_found = false;
	for (; it != this->_users.end() && !is_found; ++it) {
		if (it->getId() == userId)
			is_found = true;
	}
	if (!is_found)
		throw ObjectNotFoundException();
	typedef typename std::vector<Book>::iterator it_book;
	it_book itb = this->_books.begin();
	is_found = false;
	for (; itb != this->_books.end() && !is_found; ++itb) {
		if (itb->getId() == bookId) {
			if (itb->getBorrowerId() != 0)
				throw BookUnavailableException(); 
			itb->setBorrowerId(userId);
			is_found = true;
		}
	}
	if (!is_found)
		throw ObjectNotFoundException();
}

