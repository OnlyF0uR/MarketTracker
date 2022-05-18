#pragma once
#include <iostream>
#include <map>

template <typename T>
using FnPtr = int(*)(T);

struct Function
{
	FnPtr<std::string[]> f;
	int len;
};

// C style prototypes
int Help(std::string[]);
int List(std::string[]);
int Add(std::string[]);
int Del(std::string[]);
int View(std::string[]);

class Commands
{
public:
	Commands();
	~Commands();

	int Run(std::string cmd, std::string[]);
private:
	std::map<std::string, Function*> commands;
};