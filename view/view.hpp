#ifndef VIEW_HPP
#	define VIEW_HPP

#	include <iostream>

class View {
	public:
		View();
		~View();

		std::string prompt_str(std::string request);
		int			prompt_int(std::string request);
		void		display(std::string info);

};


#endif
