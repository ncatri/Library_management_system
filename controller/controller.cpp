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

	typedef typename std::vector<Book>::iterator iterator;
	iterator it = books.begin();
	bool	is_deleted = false;
	for (; it != books.end(); ++it) {
		if (it->getId() == ans) {
			books.erase(it);
			is_deleted = true;
			break;
		}
	}
	std::string msg;
	if (!is_deleted){
		msg = std::string("Book with id ") + std::to_string(ans) + std::string(" not found.");
	} else {
		msg = std::string("Book with id ") + std::to_string(ans) + std::string(" successfully deleted.");
	}
	this->_view.display(msg);
}

void	Controller::delete_user() { // template??
	std::vector<User>& users(this->_model.getUsers());
	this->_view.display("Users currently in library:");
	this->_view.display_vector_objs(users);
	int ans = this->_view.prompt_int("Please type id of user to delete:");

	typedef typename std::vector<User>::iterator iterator;
	iterator it = users.begin();
	bool	is_deleted = false;
	for (; it != users.end(); ++it) {
		if (it->getId() == ans) {
			users.erase(it);
			is_deleted = true;
			break;
		}
	}
	std::string msg;
	if (!is_deleted){
		msg = std::string("User with id ") + std::to_string(ans) + std::string(" not found.");
	} else {
		msg = std::string("User with id ") + std::to_string(ans) + std::string(" successfully deleted.");
	}
	this->_view.display(msg);
}
void	Controller::quit_action() {
	this->_view.display("In quit");
}

void	Controller::add_book() {
	this->_view.display("Adding a new book to library");
}

void	Controller::run() {
	int answer;
	while (true) {
		answer = this->_view.prompt_actionList();
		if (answer == ADD_BOOK)
			this->add_book();
		if (answer == DELETE_BOOK)
			this->delete_book();
		else if (answer == DELETE_USER)
			this->delete_user();
		else if (answer == QUIT) {
			this->quit_action();
			break;
		}
		else
			this->_view.display("Functionality not implemented yet.");
		this->_view.prompt_continue();
	}
}
