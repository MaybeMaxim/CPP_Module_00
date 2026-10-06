#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	_contactAmout = 0;
	_oldestContactIndex = 0;
}

std::string askForInput(const std::string &prompt)
{
	std::string input;

	std::cout << prompt;
	if (!std::getline(std::cin, input))
		return ("");
	if (!input.empty())
		return (input);
	std::cerr << "Error: Field can't be empty" << std::endl;
	return ("");
}

void	PhoneBook::addContact(void)
{
	Contact		contact;
	std::string	input;

	input = askForInput("First name: ");
	if (!contact.setFirstName(input))
		return;
	input = askForInput("Last name: ");
	if (!contact.setLastName(input))
		return;
	input = askForInput("Nickname: ");
	if (!contact.setNickname(input))
		return;
	input = askForInput("Phone number: ");
	if (!contact.setPhoneNumber(input))
		return;
	input = askForInput("Darkest secret: ");
	if (!contact.setDarkestSecret(input))
		return;

	_contactList[_oldestContactIndex] = contact;
	_oldestContactIndex = (_oldestContactIndex + 1) % 8;
	if (_contactAmout < 8)
		_contactAmout++;
}

std::string formatColumn(const std::string &name, const std::string::size_type columnWidth)
{
	if (name.length() > columnWidth)
		return (name.substr(0, 9) + '.');
	return (name);
}

void	putColumn(const std::string &name)
{
	const std::string::size_type	columnWidth = 10;
	
	std::cout << std::right << std::setw(static_cast<int>(columnWidth)) << formatColumn(name, columnWidth);
	std::cout.put('|');
}

void	putRow(const std::string &name1, const std::string &name2, const std::string &name3, const std::string &name4)
{
	std::cout.put('|');
	putColumn(name1);
	putColumn(name2);
	putColumn(name3);
	putColumn(name4);
	std::cout.put('\n');
}

void	PhoneBook::printContactTable(void)
{
	putRow("index", "first name", "last name", "Nickname");
	for (int i = 0; i < _contactAmout; i++)
	{
		std::string index(1, static_cast<char>('0' + i));
		putRow(index,
		 _contactList[i].getFirstName(),
		 _contactList[i].getLastName(),
		 _contactList[i].getNickname());
	}
}

bool	parseIndex(std::string &str, int &index, const int &_contactAmout)
{
	if (str.length() != 1)
	{
		std::cout << "more then 1";
		return (false);
	}
	index = str[0] - '0';
	if (index >= 0 && index < _contactAmout)
		return (true);
	else
		return (false);
}

void	PhoneBook::searchContact(void)
{
	std::string	input;
	int			index;

	if (_contactAmout != 0)
		printContactTable();
	else
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return;
	}
	std::cout << std::endl;
	input = askForInput("Enter contact index: ");
	if (input.empty())
	{
		std::cout << "No index was provided" << std::endl;
		return;
	}
	if (!parseIndex(input, index, _contactAmout))
	{
		std::cout << "Invalid index was provided" << std::endl;
		return;
	}
	_contactList[index].showContactInfo();
}
