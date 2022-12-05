#ifndef CONTROLLER_HPP
#	define CONTROLLER_HPP

#	include "view.hpp"
#	include "model.hpp"

class Controller {
	public:
		Controller(Model& model, View view);
		~Controller();

		void	run();

	private:

		Model&	_model;
		View	_view;

		void	delete_book();
		void	delete_user();
		void	add_book();
		void	add_user();
		void	rent_book();
		void	quit_action();
		void	show_data();
		void	return_book();
		void	show_rented_books();
};

#endif
