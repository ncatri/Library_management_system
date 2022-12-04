#include "controller.hpp"

Controller::Controller(Model& model, View view) : _model(model) {
	this->_view = view;
}

Controller::~Controller() {}

void	Controller::showdata() {
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
	this->_view.display("In quit");
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
	}
	catch (std::exception& e) {
		this->_view.display(e.what());
	}
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
		else if (answer == QUIT) {
			this->quit_action();
			break;
		}
		else if (answer == RENT_BOOK)
			this->rent_book();
		else
			this->_view.display("Functionality not implemented yet.");
		this->_view.prompt_continue();
	}
}
