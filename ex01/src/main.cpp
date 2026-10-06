#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void	runCommand(std::string &input, PhoneBook &PhoneBook)
{
	if (input == "ADD")
	{
		PhoneBook.addContact();
	}
	else if (input == "SEARCH")
	{
		PhoneBook.searchContact();
	}
	else if (input == "EXIT")
	{
		std::cout << "Stoping program...";
		exit(0);
	}
	std::cout << std::endl;
}

int	main(void)
{
	PhoneBook	PhoneBook;
	Contact		Contact;
	std::string	input;

	while (true)
	{
		std::cout << "Command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, input))
			return (1);
		runCommand(input, PhoneBook);
	}
	return (0);
}
