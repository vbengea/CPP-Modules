NAME = PmergeMe

SRCS = main.cpp \
		PmergeMe.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -O3

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) # -lrt

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

run: all clean
	clear
	./$(NAME) 3 5 9 7 4
	./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "`

re: fclean all

.PHONY: all clean fclean re run