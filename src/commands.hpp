#pragma once
#include <iostream>
#include <unordered_map>

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

	int Run(std::string cmd, std::string[]);
private:
	std::unordered_map<std::string, Function> commands;
};