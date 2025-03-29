NAME = Attack

SRCS = main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp

CC = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re