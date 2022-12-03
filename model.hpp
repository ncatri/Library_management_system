#ifndef MODEL_HPP
#	define MODEL_HPP

#	include <iostream>
#	include <vector>
#	include <map>

class Book {
	public:
		Book();
		~Book();
		Book(int id);

		int 		getId() const;
		std::string	getTitle() const;

	private:
		int			_id;
		std::string	_title;
		bool		_is_rented;
};

class User {
	public:
		User();
		~User();
		User(int id);

	private:
		int 		_id;
		std::string	_name;
};

class Library {
	public:
		Library();
		~Library();
		void	addBook(Book newBook);
		void	deleteBook(int	bookId);

		void	addUser(User newUser);
		void	deleteUser(int	userId);

	private:
		std::vector<Book>	books;
		std::vector<User>	users;

};

class View {

	public:

		View(Library& library);
		~View();

		void showRentedBooks() {
			std::cout << "showing rented books" << std::endl;
		}

		void askForAction() {
			std::cout << "What do you want to do?" << std::endl;
		}


	private:
		Library& _library;
};


#endif
