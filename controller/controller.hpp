#ifndef CONTROLLER_HPP
#	define CONTROLLER_HPP

#	include "view.hpp"
#	include "model.hpp"

class Controller {
	public:
		Controller(Model& model, View view);
		~Controller();

		void	showdata();

	private:

		Model&	_model;
		View	_view;

};

#endif
