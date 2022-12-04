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
	std::cout << request;
	int answer;
	std::cin >> answer;

	return (answer);
}

void	View::display(std::string info) {
	std::cout << info << std::endl;
}
