/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea < vbengea@student.42madrid.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:44:42 by vbengea           #+#    #+#             */
/*   Updated: 2025/03/17 20:44:22 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

int	PhoneBook::_oldestIndex = 0;

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
	std::string phoneNumber;
	std::string darkestSecret;

	do {
		std::cout << "Enter first name: ";
		std::getline(std::cin, firstName);
	} while (firstName.empty());

	do {
		std::cout << "Enter last name: ";
		std::getline(std::cin, lastName);
	} while (lastName.empty());

	do {
		std::cout << "Enter nickname: ";
		std::getline(std::cin, nickName);
	} while (nickName.empty());

	do {
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phoneNumber);
	} while (phoneNumber.empty());

	do {
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, darkestSecret);
	} while (darkestSecret.empty());

	firstName = truncateString(firstName);
	lastName = truncateString(lastName);
	nickName = truncateString(nickName);
	darkestSecret = truncateString(darkestSecret);


	int index = -1;
	for (int i = 0; i < 8; i++) {
		if (this->_contacts[i].getIndex().empty()) {
			index = i;
			break ;
		}
	}

	if (index == -1) {
		index = _oldestIndex;
		_oldestIndex = (index + 1) % 8;
	}


	this->_contacts[index].getIndex();
	this->_contacts[index].setFirstName(firstName);
	this->_contacts[index].setLastName(lastName);
	this->_contacts[index].setNickName(nickName);
	this->_contacts[index].setIndex(intToString(index));
	this->_contacts[index].setPhoneNumber(phoneNumber);
	this->_contacts[index].setDarkestSecret(darkestSecret);
}

std::string PhoneBook::intToString(int num) {
	std::ostringstream ss;
	ss << num;
	return ss.str();
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

	std::string indexStr;
	std::cout << "Enter the index of the contact you want to view: ";
	std::getline(std::cin, indexStr);

	std::istringstream iss(indexStr);
	int index;
	if (!(iss >> index)) {
		std::cout << "Invalid input. Please enter a number." << std::endl;
		return;
	}

	if (index >= 0 && index < 8 && !this->_contacts[index].getIndex().empty()) {
		std::cout << "First Name: " << this->_contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << this->_contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << this->_contacts[index].getNickName() << std::endl;
		std::cout << "Phone Number: " << this->_contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
	} else {
		std::cout << "Invalid index or empty contact." << std::endl;
	}
}