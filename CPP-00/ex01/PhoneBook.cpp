/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea <vbengea@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:44:42 by vbengea           #+#    #+#             */
/*   Updated: 2025/03/12 12:51:30 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::addContact(void) {
	std::cout << "First name: ";
	std::cin >> this->_firstName;
	std::cout << "Last name: ";
	std::cin >> this->_lastName;
	std::cout << "Nick name: ";
	std::cin >> this->_nickName;
	std::cout << "Index: ";
	std::cin >> this->_index;
	std::cout << "Darkest secret: ";
	std::cin >> this->_darkestSecret;
}

void PhoneBook::searchContact(void) {
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nick name: " << this->_nickName << std::endl;
	std::cout << "Index: " << this->_index << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}