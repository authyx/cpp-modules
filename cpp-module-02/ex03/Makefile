NAME = main

INCLUDES = Fixed.hpp Point.hpp
SRCS = Fixed.cpp Fixed2.cpp main.cpp Point.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
VERSION = -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(VERSION) $(OBJS) -o $(NAME)

no_version: fclean $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) $(VERSION) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all no_version clean fclean re
.SECONDARY: $(OBJS)