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
		std::string	getTitle1() const;
		std::string	getTitle2() const;
		std::string	getAuthor1() const;
		std::string	getAuthor2() const;
		int			getBorrowerId() const;

	private:
		const int			_id;
		const std::string	_title1;
		const std::string	_title2;
		const std::string	_author1;
		const std::string	_author2;
		int					_borrowerId;
};

std::ostream& operator<<( std::ostream& o, Book& rhs);
std::ofstream& operator<<( std::ofstream& o, Book& rhs);

class User {
	public:
		User();
		~User();
		User(int id, std::string name, std::string surname);
		
		int			getId() const;
		std::string getName() const;
		std::string getSurname() const;

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
