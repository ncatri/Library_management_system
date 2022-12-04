#ifndef BOOK_HPP
#	define BOOK_HPP

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

		void		setBorrowerId(int id);

	private:
		const int			_id;
		const std::string	_title1;
		const std::string	_title2;
		const std::string	_author1;
		const std::string	_author2;
		int					_borrowerId;
};

std::ostream& operator<<( std::ostream& o, Book& rhs);

#endif
