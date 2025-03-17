/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea < vbengea@student.42madrid.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:44:42 by vbengea           #+#    #+#             */
/*   Updated: 2025/03/17 11:06:36 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
	std::string index;

	std::cout << "Enter index: ";
	std::getline(std::cin, index);
	for (int i = 0; i < 8; i++) {
		if (this->_contacts[i].getIndex() == index) {
			std::cout << "First name: " << this->_contacts[i].getFirstName() << std::endl;
			std::cout << "Last name: " << this->_contacts[i].getLastName() << std::endl;
			std::cout << "Nickname: " << this->_contacts[i].getNickName() << std::endl;
			std::cout << "Darkest secret: " << this->_contacts[i].getDarkestSecret() << std::endl;
			break ;
		}
	}
}
