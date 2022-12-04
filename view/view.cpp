#include "view.hpp"

View::View() {}
View::~View() {}

std::string	View::prompt_str(std::string request) {
	std::cout << request;
	std::string answer;
	std::cin >> answer;

	return (answer);
}

int		View::prompt_int(std::string request) {
	std::cout << request << std::endl;
	int answer;
	std::cin >> answer;

	return (answer);
}

void	View::display(std::string info) {
	std::cout << info << std::endl;
}

void	View::prompt_continue() {
	std::cout << "Type something to continue" << std::endl;
	std::cin.get();
}

int		View::prompt_actionList() {
	int answer = 0;
	std::string prompt("Please type corresponding number for one of the following actions:\n1. Add a book\n2. Delete a book\n3. Add an user\n4. Delete an user\n5. Show rented books\n6. Rent a book\n7. Return a book\n8. Quit and save\n");

	while ((answer = this->prompt_int(prompt)) <= 0 || answer > QUIT)
		this->display("Invalid answer. Please try again");
	return (answer);
}
