NAME = ExThree
CXX = c++
CXXFLAGS = -Wall -Wextra -Wall -std=c++98

SRC = Fixed.cpp main.cpp Point.cpp bsp.cpp
OBJS = $(SRC:.cpp=.o)
all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 