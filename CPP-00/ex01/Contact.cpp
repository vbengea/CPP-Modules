/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea < vbengea@student.42madrid.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:37:55 by vbengea           #+#    #+#             */
/*   Updated: 2025/03/17 11:29:52 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	std::cout << "Contact created" << std::endl;
	this->_firstName = "";
	this->_lastName = "";
	this->_nickName = "";
	this->_index = "";
	this->_darkestSecret = "";
	this->_phoneNumber = "";
}

Contact::~Contact(void) {
	std::cout << "Contact destroyed" << std::endl;
	this->_firstName = "";
	this->_lastName = "";
	this->_nickName = "";
	this->_index = "";
	this->_darkestSecret = "";
	this->_phoneNumber = "";
}

void Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
}

void Contact::setNickName(std::string nickName) {
	this->_nickName = nickName;
}

void Contact::setIndex(std::string index)
{
	this->_index = index;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

std::string Contact::getPhoneNumber(void) const {
	return this->_phoneNumber;
}

std::string Contact::getFirstName(void) const {
	return this->_firstName;
}

std::string Contact::getLastName(void) const {
	return this->_lastName;
}

std::string Contact::getNickName(void) const {
	return this->_nickName;
}

std::string Contact::getIndex(void) const {
	return this->_index;
}

std::string Contact::getDarkestSecret(void) const {
	return this->_darkestSecret;
}
