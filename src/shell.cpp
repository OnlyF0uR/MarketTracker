#include "shell.hpp"
#include <iostream>
#include <io.h>
#include <sstream>
#include "commands.hpp"

#define STDIN_FILENO 0

Shell::Shell()
{
	this->CmdHandler = new Commands();
}

Shell::~Shell()
{
	delete this->CmdHandler;
}

void Shell::MainLoop()
{
	std::string cmd;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			std::cout << "--> ";
		}

		std::getline(std::cin, cmd);

		if (cmd.compare("exit") == 0 ||
			cmd.compare("quit") == 0)
		{
			break;
		}

		std::string args[2];
		int i = 0;

		std::stringstream ss(cmd);
		while (ss.good() && i < 3)
		{
			std::string s;
			ss >> s;
			if (i == 0)
			{
				cmd = s;
			}
			else
			{
				args[i - 1] = s;
			}
			++i;
		}

		if (CmdHandler->Run(cmd, args) == 1)
		{
			std::cout << "An error occurred\n";
			break;
		}
	}
}