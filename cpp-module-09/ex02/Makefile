NAME = PmergeMe

INCLUDES = PmergeMe.hpp
SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
VERSION = -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(VERSION) $(OBJS) -o $(NAME)

nf: CXXFLAGS = 
nf: all

%.o: %.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) $(VERSION) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all no_version clean fclean re
.SECONDARY: $(OBJS)