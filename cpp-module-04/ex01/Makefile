NAME = main

 INCLUDES= Animal.hpp  Brain.hpp  Cat.hpp  Dog.hpp  \
		WrongAnimal.hpp  WrongCat.hpp 
SRCS = Animal.cpp  Brain.cpp  Cat.cpp  Dog.cpp  \
		WrongAnimal.cpp  WrongCat.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

# CXX = c++
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