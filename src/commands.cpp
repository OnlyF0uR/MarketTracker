#include "commands.hpp"
#include <string>

Commands::Commands()
{
	// Help command
	Function *help = new Function();
	help->f = &Help;
	help->len = 0;
	this->commands["help"] = help;

	// View command
	Function* view = new Function();
	view->f = &View;
	view->len = 1;
	this->commands["view"] = view;
}

Commands::~Commands()
{
	for (auto const& x : this->commands)
	{
		delete x.second;
	}

	this->commands.clear();
}

int Commands::Run(std::string cmd, std::string args[])
{
	if (this->commands.count(cmd))
	{
		int c = -1;
		for (int i = 0; i < 3; i++)
		{
			if (!args[i].empty())
			{
				c++;
			}
		}

		Function* f = commands[cmd];

		if (c < f->len)
		{
			std::cout << "Invalid amount of parameters, please use the help command\n";
			return 0;
		}

		f->f(args);
	}
	else
	{
		// We do not really need an extra check here
		Help(nullptr);
	}

	return 0;
}

int View(std::string args[])
{
	for (char const& c : args[0])
	{
		if (std::isdigit(c) == 0)
		{
			std::cout << "The first parameter should be an integer.\n";
			return 0;
		}
	}

	int i = std::stoi(args[0]);
	// TODO: Get data given above defined integer

	std::string pool = "example pool";
	std::string sellAt = "1";

	std::cout << "Currently watching:\nPool: " << pool << "\nSell at: " << sellAt << "\n";
	return 0;
}

int Help(std::string _[]) {
	std::cout << "This is a help message!\n";
	return 0;
}