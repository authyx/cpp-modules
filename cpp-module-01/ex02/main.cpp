#include <string>
#include <iostream>

#define cout std::cout 
#define cin std::cin 
#define string std::string 
#define endl std::endl 

void	puthex(long l)
{
	string table = "0123456789abcdef";
	if (l > 16)
		puthex(l / 16);
	cout << table[l % 16];
}

void	memory_print(void *p)
{
	if (p == NULL)
	{
		cout << "0x00000000" << endl;
		return ;
	}
	puthex(*(long *)p);
	cout << endl;
}

int main()
{
	string msg = "HI THIS IS BRAIN";
	string *ptr = &msg;
	string &ref = msg;
	memory_print(&msg);
	memory_print(ptr);
	memory_print(&ref);
	cout << msg << endl;
	cout << *ptr << endl;
	cout << ref << endl;
	return 0;
}


