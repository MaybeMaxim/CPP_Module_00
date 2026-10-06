#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:
		Contact(void);

		bool setFirstName(const std::string &firstName);
		bool setLastName(const std::string &lastName);
		bool setNickname(const std::string &nickname);
		bool setPhoneNumber(const std::string &phoneNumber);
		bool setDarkestSecret(const std::string &darkestSecret);

		const std::string &getFirstName(void) const;
		const std::string &getLastName(void) const;
		const std::string &getNickname(void) const;
		const std::string &getPhoneNumber(void) const;
		const std::string &getDarkestSecret(void) const;

		void	showContactInfo(void) const;

	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif
