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
