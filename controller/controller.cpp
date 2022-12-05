#include "controller.hpp"

Controller::Controller(Model& model, View view) : _model(model) {
	this->_view = view;
}

Controller::~Controller() {}

void	Controller::show_data() {
	this->_view.display("showing books:");
	this->_view.display_vector_objs(this->_model.getBooks());
	this->_view.display("showing users:");
	this->_view.display_vector_objs(this->_model.getUsers());
}

void	Controller::delete_book() { // template??
	std::vector<Book>& books(this->_model.getBooks());
	this->_view.display("Books currently in library:");
	this->_view.display_vector_objs(books);
	int ans = this->_view.prompt_int("Please type id of book to delete:");
	std::string msg;
	try {
		this->_model.deleteObj<Book>(books, ans);
		msg = std::string("Book with id ") + std::to_string(ans) + std::string(" successfully deleted.");
		this->_view.display(msg);
		}
		catch (std::exception& e) {
			msg = std::string("Book with id ") + std::to_string(ans) + std::string(" not found.");
			this->_view.display(msg);
		}
}

void	Controller::delete_user() { 
	std::vector<User>& users(this->_model.getUsers());
	this->_view.display("Users currently in library:");
	this->_view.display_vector_objs(users);
	int ans = this->_view.prompt_int("Please type id of user to delete:");
	std::string msg;
	try {
		this->_model.deleteObj<User>(users, ans);
		msg = std::string("User with id ") + std::to_string(ans) + std::string(" successfully deleted.");
		this->_view.display(msg);
	}
	catch (std::exception& e) {
		msg = std::string("User with id ") + std::to_string(ans) + std::string(" not found.");
		this->_view.display(msg);
	}
}

void	Controller::quit_action() {
	std::string ans = this->_view.prompt_str("Save? [Y/n]");
	if (ans.compare("n") == 0 || ans.compare("no") == 0)
		this->_view.display("Goodbye! (session not registered)");
	else {
		this->_model.getFileOperator().saveObjects(this->_model.getBooks(), this->_model.getFileOperator().getBooksFileName());
		this->_model.getFileOperator().saveObjects(this->_model.getUsers(), this->_model.getFileOperator().getUsersFileName());
		this->_view.display("Goodbye! (session successfully registered)");
	}
}

void	Controller::add_book() {
	this->_view.display("Adding a new book to library");
	std::vector<Book> books = this->_model.getBooks();
	std::string title = this->_view.prompt_str("Title: ");
	std::string author = this->_view.prompt_str("Author: ");
	int id = this->_model.getIdMax<Book>(books) + 1;
	Book newBook(id, title, "title2", author, "author2", 0);
	try {
		this->_model.addBook(newBook);
		this->_view.display("New book added: ");
		this->_view.display_obj<Book>(newBook);
	}
	catch (std::bad_alloc const&){
		this->_view.display("A memory error occured, couldn't proceed");
	}
}

void	Controller::add_user() {
	this->_view.display("Adding a new user to library");
	std::vector<User> users = this->_model.getUsers();
	std::string name = this->_view.prompt_str("Name: ");
	std::string surname = this->_view.prompt_str("Surname: ");
	int id = this->_model.getIdMax<User>(users) + 1;
	User newUser(id, name, surname);
	try {
		this->_model.addUser(newUser);
		this->_view.display("New user added: ");
		this->_view.display_obj<User>(newUser);
	}
	catch (std::bad_alloc const&){
		this->_view.display("A memory error occured, couldn't proceed");
	}
}

void	Controller::rent_book() {
	int userId = this->_view.prompt_int("Select user id: ");
	int bookId = this->_view.prompt_int("Select book to borrow id: ");
	try {
		this->_model.rentBook(userId, bookId);
		this->_view.display("Operation successfully completed");
	}
	catch (std::exception& e) {
		this->_view.display(e.what());
	}
}

void	Controller::return_book() {
	this->_view.display("In return_book");
}

void	Controller::show_rented_books() {
	std::vector<Book> books = this->_model.getBooks();
	bool is_empty = true;
	typedef std::vector<Book>::iterator iterator;
	for (iterator it = books.begin(); it != books.end(); ++it){
		if (it->getBorrowerId() != 0) {
			this->_view.display_obj<Book>(*it);
			is_empty = false;
		}
	}
	if (is_empty)
		this->_view.display("There is no rented book yet.");
}

void	Controller::run() {
	int answer;
	while (true) {
		answer = this->_view.prompt_actionList();
		if (answer == ADD_BOOK)
			this->add_book();
		else if (answer == DELETE_BOOK)
			this->delete_book();
		else if (answer == ADD_USER)
			this->add_user();
		else if (answer == DELETE_USER)
			this->delete_user();
		else if (answer == RENT_BOOK)
			this->rent_book();
		else if (answer == RETURN_BOOK)
			this->return_book();
		else if (answer == SHOW_RENTED_BOOKS)
			this->show_rented_books();
		else if (answer == SHOW_DATA)
			this->show_data();
		else if (answer == QUIT) {
			this->quit_action();
			break;
		}
		else
			this->_view.display("Functionality not implemented yet.");
		this->_view.prompt_continue();
	}
}
