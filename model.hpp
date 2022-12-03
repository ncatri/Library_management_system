#ifndef MODEL_HPP
#	define MODEL_HPP

#	include <iostream>
#	include <vector>

class Book {
	public:
		Book();
		~Book();
		Book(int id, std::string title1, std::string title2,\
				std::string author1, std::string author2, int borrowerId);

		int 		getId() const;
		std::string	getTitle() const;
		std::string	getAuthor() const;
		int			getBorrowerId() const;

	private:
		const int			_id;
		const std::string	_title;
		const std::string	_author;
		int					_borrowerId;
};

std::ostream& operator<<( std::ostream& o, Book& rhs);

class User {
	public:
		User();
		~User();
		User(int id);
		
		int			getId() const;
		std::string getName() const;

	private:
		int 		_id;
		std::string	_name;
		std::string	_surname;
};

std::ostream& operator<<( std::ostream& o, User& rhs);

class Model {
	public:
		Model(std::vector<Book> books, std::vector<User> users);
		~Model();

	private:
		std::vector<Book> 	_books;
		std::vector<User> 	_users;
		//FileOperator		_fileOp;
};

//controller
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
