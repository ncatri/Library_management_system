#include "view.hpp"

View::View() {}
View::~View() {}

std::string	View::prompt_str(std::string request) {
	std::cout << request;
	std::string answer;
	std::getline(std::cin, answer);

	return (answer);
}

int		View::prompt_int(std::string request) {
	std::cout << request; 
	int ret_ans;
	std::string ans;
	std::getline(std::cin, ans);
	std::stringstream(ans) >> ret_ans;

	return (ret_ans);
}

void	View::display(std::string info) {
	std::cout << info << std::endl;
}

void	View::prompt_continue() {
	std::cout << "Press enter to continue...";
	std::string discard;
	std::getline(std::cin, discard);
}

int		View::prompt_actionList() {
	int answer = 0;
	std::string prompt("Please type corresponding number for one of the following actions:\n1. Add a book\n2. Delete a book\n3. Add an user\n4. Delete an user\n5. Show rented books\n6. Rent a book\n7. Return a book\n8. Show data\n9. Quit\n");
	answer = this->prompt_int(prompt);

	return (answer);
}
