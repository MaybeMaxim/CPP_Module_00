#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);

		void	addContact(void);
		void	searchContact(void);

	private:
		Contact _contactList[8];
		int		_contactAmout;
		int		_oldestContactIndex;

		void	printContactTable(void);
};

#endif
