CPPFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
CXX = c++

NAME = run

USERS_INPUTFILE = abonnes.csv
BOOKS_INPUTFILE = livres.csv
USERS_DB = abonnes.db
BOOKS_DB = livres.db

SRCS = extract_data.cpp 				\

OBJS_FOLDER = bin
OBJS = $(addprefix $(OBJS_FOLDER)/, $(SRCS:.cpp=.o))

HEADERS = $(SRCS:.cpp=.hpp)

$(OBJS_FOLDER)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADERS) main.cpp
	$(CXX) $(CPPFLAGS) $(OBJS) main.cpp -o $(NAME)

clean:
	$(RM) -r $(OBJS_FOLDER)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(NAME).dSYM

re: fclean $(NAME)

livres_db:
	cat $(BOOKS_INPUTFILE) | cut -f3-6 -d ";" | grep -v "Article de REGLES" | awk '{if (NR>1) printf "%d;%s;0\n", NR - 1, $$0}' > $(BOOKS_DB)

abonnes_db:
	tail -n +2 $(USERS_INPUTFILE) > $(USERS_DB)

clean_db:
	rm $(BOOKS_DB) $(USERS_DB)

databases: abonnes_db livres_db

.PHONY:	clean fclean re clean_db
