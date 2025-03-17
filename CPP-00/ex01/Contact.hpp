/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea < vbengea@student.42madrid.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:31:15 by vbengea           #+#    #+#             */
/*   Updated: 2025/03/17 11:27:56 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
	public:
		Contact(void);
		~Contact(void);

		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setNickName(std::string nickName);
		void setIndex(std::string index);
		void setDarkestSecret(std::string darkestSecret);
		void setPhoneNumber(std::string phoneNumber);

		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickName(void) const;
		std::string getIndex(void) const;
		std::string getDarkestSecret(void) const;
		std::string getPhoneNumber(void) const;

	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _index;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif