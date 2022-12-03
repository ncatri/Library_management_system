CPPFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
CXX = c++

NAME = run

SRCS = extract_data.cpp 				\

OBJS_FOLDER = bin
OBJS = $(addprefix $(OBJS_FOLDER)/, $(SRCS:.cpp=.o))

HEADERS = $(SRCS:.cpp=.hpp)

$(OBJS_FOLDER)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADERS) main.cpp
	$(CXX) $(CPPFLAGS) $(OBJS) main.cpp -o $(NAME)

test:
	echo sources: $(SRCS)
	echo objets: $(OBJS)
	echo headers: $(HEADERS)

clean:
	$(RM) -r $(OBJS_FOLDER)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(NAME).dSYM

re: fclean $(NAME)

clean_data:
	cat livres.csv | cut -f3-6 -d ";" | grep -v "Article de REGLES"


.PHONY:	clean fclean re
