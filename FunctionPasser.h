#pragma once
#include <functional>
#include <atomic>

template <typename Caller>
//using funcPtr = int (Caller::*)(void);
using funcPtr = std::function<int(Caller*, const std::string str)>;
template <typename Caller>
class FunctionPasser
{
public:
	FunctionPasser() = delete;


	FunctionPasser(Caller* caller, funcPtr<Caller> functionPointer) : _caller(caller), _funcToCall (functionPointer) {}


	void Run()
	{
		while (_running)
		{
			Call();
		}
	}

	int Call()
	{
		//wait on event
		//return funcPtr<Caller>(_caller->_func)();
		return _funcToCall(_caller, "");
	}
private:

	Caller* _caller{ nullptr };
	//funcPtr<Caller> _func;
	funcPtr<Caller> _funcToCall;

	std::atomic_bool _running{ false };
};
