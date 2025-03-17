/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea < vbengea@student.42madrid.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:44:42 by vbengea           #+#    #+#             */
/*   Updated: 2025/03/17 19:52:40 by vbengea          ###   ########.fr       */
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
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickName);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);

	firstName = truncateString(firstName);
	lastName = truncateString(lastName);
	nickName = truncateString(nickName);
	darkestSecret = truncateString(darkestSecret);

	for (int i = 0; i < 8; i++) {
		if (this->_contacts[i].getIndex().empty()) {
			this->_contacts[i].setFirstName(firstName);
			this->_contacts[i].setLastName(lastName);
			this->_contacts[i].setNickName(nickName);
			this->_contacts[i].setIndex(intToString(i));
			this->_contacts[i].setPhoneNumber(phoneNumber);
			this->_contacts[i].setDarkestSecret(darkestSecret);
			break ;
		}
	}
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