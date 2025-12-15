#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

RPN::RPN(const RPN &other) : stack(other.stack) {}
RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		stack = other.stack;
	}
	return *this;
}

void RPN::performOperation(char op)
{
	if (stack.size() < 2)
	{
		throw std::runtime_error("Insufficient operands for operation");
	}

	float right = stack.top();
	stack.pop();
	float left = stack.top();
	stack.pop();

	float result;
	switch (op)
	{
	case '+':
		result = left + right;
		break;
	case '-':
		result = left - right;
		break;
	case '*':
		result = left * right;
		break;
	case '/':
	{

		if (right == 0)
		{
			throw std::runtime_error("Division by zero");
		}
		result = left / right;
		break;
	}
	default:
		throw std::invalid_argument("Invalid operator");
	}

	stack.push(result);
}

float RPN::evaluate(const std::string &expression)
{
	for (size_t i = 0; i < expression.size(); ++i)
	{
		char token = expression[i];
		if (isdigit(token))
		{
			stack.push(token - '0');
		}
		else if (token == '+' || token == '-' || token == '*' || token == '/')
		{
			performOperation(token);
		}
		else if (token != ' ')
		{
			throw std::invalid_argument("Invalid character in expression");
		}
	}

	if (stack.size() != 1)
	{
		throw std::runtime_error("Invalid expression");
	}

	return stack.top();
}