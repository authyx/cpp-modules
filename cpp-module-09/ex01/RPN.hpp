#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <stdexcept>

class RPN
{
private:
	std::stack<float> stack;
	void performOperation(char op);

public:
	RPN();
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	float evaluate(const std::string &expression);
};

#endif
