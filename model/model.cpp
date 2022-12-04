#include "model.hpp"

Model::Model(std::string book_file_path, std::string user_file_path):
	_fileOperator(book_file_path, user_file_path) {

	this->_books = this->_fileOperator.loadBooks();
	this->_users = this->_fileOperator.loadUsers();
}

Model::~Model() {}

std::vector<Book>&	Model::getBooks() { return (this->_books); }
std::vector<User>&	Model::getUsers() { return (this->_users); }
