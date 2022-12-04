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

void	Controller::delete_book_action() {
	this->_view.display("In delete book");

}

void	Controller::quit_action() {
	this->_view.display("In quit");
}

void	Controller::run() {
	int answer;
	while (true) {
		answer = this->_view.prompt_actionList();
		if (answer == DELETE_BOOK)
			this->delete_book_action();
		else if (answer == QUIT) {
			this->quit_action();
			break;
		}
		else
			this->_view.display("Functionality not implemented yet.");
		this->_view.prompt_continue();
	}
}
