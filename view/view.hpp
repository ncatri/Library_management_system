#ifndef VIEW_HPP
#	define VIEW_HPP

#	include <iostream>
#	include <vector>

enum action {
	ADD_BOOK = 1,
	DELETE_BOOK,
	ADD_USER,
	DELETE_USER,
	SHOW_RENTED_BOOKS,
	RENT_BOOK,
	RETURN_BOOK,
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
