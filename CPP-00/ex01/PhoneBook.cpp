/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea < vbengea@student.42madrid.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:44:42 by vbengea           #+#    #+#             */
/*   Updated: 2025/03/17 13:12:35 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

std::string PhoneBook::truncateString(std::string str) {
	if (str.length() > 10) {
		str = str.substr(0, 9) + ".";
	}
	return str;
}

PhoneBook::PhoneBook(void) {
	std::cout << "PhoneBook created" << std::endl;
	for (int i = 0; i < 8; i++) {
		this->_contacts[i].setIndex("");
	}
}
PhoneBook::~PhoneBook(void) {
	std::cout << "PhoneBook destroyed" << std::endl;
	for (int i = 0; i < 8; i++) {
		this->_contacts[i].setIndex("");
	}
}

void PhoneBook::addContact(void) {
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string index;
	std::string darkestSecret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickName);
	std::cout << "Enter index: ";
	std::getline(std::cin, index);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);

	firstName = truncateString(firstName);
	lastName = truncateString(lastName);
	nickName = truncateString(nickName);
	index = truncateString(index);
	darkestSecret = truncateString(darkestSecret);

	for (int i = 0; i < 8; i++) {
		if (this->_contacts[i].getIndex().empty()) {
			this->_contacts[i].setFirstName(firstName);
			this->_contacts[i].setLastName(lastName);
			this->_contacts[i].setNickName(nickName);
			this->_contacts[i].setIndex(index);
			this->_contacts[i].setDarkestSecret(darkestSecret);
			break ;
		}
	}
}


void PhoneBook::searchContact(void) {
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;

	std::cout << std::string(43, '-') << std::endl;
	std::cout << std::setfill(' ');

	for (int i = 0; i < 8; i++) {
		if (!this->_contacts[i].getIndex().empty()) {
			std::cout << std::setw(10) << this->_contacts[i].getIndex() << "|";
			std::cout << std::setw(10) << this->_contacts[i].getFirstName() << "|";
			std::cout << std::setw(10) << this->_contacts[i].getLastName() << "|";
			std::cout << std::setw(10) << this->_contacts[i].getNickName() << "|" << std::endl;
		}
	}
}