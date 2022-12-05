#include "extract_data.hpp"

FileOperator::FileOperator( std::string books_file_path, std::string users_file_path): _books_file_name(books_file_path), _users_file_name(users_file_path) {}

FileOperator::~FileOperator() {}

std::string FileOperator::getBooksFileName() const {
	return (this->_books_file_name);
}

std::string FileOperator::getUsersFileName() const {
	return (this->_users_file_name);
}

std::vector<Book> FileOperator::loadBooks() {
	std::vector<std::string> attributes = this->fromLinesToAttributes(this->_books_file_name);
	return (this->fromAttributesToBooks(attributes));
}

std::vector<User> FileOperator::loadUsers() {
	std::vector<std::string> attributes = this->fromLinesToAttributes(this->_users_file_name);
	return (this->fromAttributesToUsers(attributes));
}

std::vector<std::string> FileOperator::fromLinesToAttributes(std::string file_name) {
	std::ifstream file(file_name);
	std::string line;
	std::vector<std::string> result;
	if (file.is_open()) {
		while (getline(file, line))
			result.push_back(line);
	}
	return (result);
}

std::vector<Book>	FileOperator::fromAttributesToBooks(std::vector<std::string> strings) {
	std::vector<Book> books;

	std::vector<std::string> attributes;
	
	typedef std::vector<std::string>::iterator iterator;
	for (iterator it = strings.begin(); it != strings.end(); ++it) {
		attributes = split(*it, ';');
		books.push_back(Book(atoi(attributes[0].c_str()), attributes[1], attributes[2], attributes[3], attributes[4], atoi(attributes[5].c_str())));
	}

	return (books);
}

std::vector<User>	FileOperator::fromAttributesToUsers(std::vector<std::string> strings) {
	std::vector<User> users;

	std::vector<std::string> attributes;
	
	typedef std::vector<std::string>::iterator iterator;
	for (iterator it = strings.begin(); it != strings.end(); ++it) {
		attributes = split(*it, ';');
		users.push_back(User(atoi(attributes[0].c_str()), attributes[1], attributes[2])); 
	}

	return (users);
}
std::vector<std::string> split(std::string str, char sep) {
	std::vector<std::string> result;
	std::stringstream sstr(str);
	std::string	fragment;

	while (std::getline(sstr, fragment, sep))
			result.push_back(fragment);
	return (result);	
}

