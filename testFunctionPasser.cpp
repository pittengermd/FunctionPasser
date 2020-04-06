#include "FunctionPasser.h"
#include <cstddef>
#include <memory>
#include <iostream>
struct TestMe
{
	std::string testString = "Asdf";
	int MyFuncA(const std::string& str = "" )
	{
		std::cout << "MyFuncA prints: " << str << std::endl;
		return 0;
	}

	int MyFuncB(const std::string& str = "" )
	{
		std::cout << "MyFuncB prints: " << str << std::endl;
		return 0;
	}
};

int main()
{
	std::unique_ptr<TestMe> _valid{ std::make_unique<TestMe>() };

	FunctionPasser<TestMe> _testA{ _valid.get(), &TestMe::MyFuncA };
	FunctionPasser<TestMe> _testB{ _valid.get(), &TestMe::MyFuncB };

	_testA.Call();
	_testB.Call();

	return 0;
}

