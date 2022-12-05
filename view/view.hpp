#ifndef VIEW_HPP
#	define VIEW_HPP

#	include <iostream>
#	include <sstream>
#	include <vector>

enum action {
	// starting at 1, 0 used for invalid user input
	ADD_BOOK = 1,
	DELETE_BOOK,
	ADD_USER,
	DELETE_USER,
	SHOW_RENTED_BOOKS,
	RENT_BOOK,
	RETURN_BOOK,
	SHOW_DATA,
	QUIT
};


class View {
	public:
		View();
		~View();

		int			prompt_actionList();
		std::string prompt_str(std::string request);
		int			prompt_int(std::string request);
		void		display(std::string info);
		void		prompt_continue();

		template <typename T>
		void		display_obj(T obj) {
			std::cout << obj << std::endl;
		}

		template <typename T>
		void	display_vector_objs(std::vector<T> vect) {
			typedef typename std::vector<T>::iterator iterator;
			for (iterator it = vect.begin(); it != vect.end(); ++it)
				this->display_obj(*it);
		}
};


#endif
