/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea < vbengea@student.42madrid.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:33:03 by vbengea           #+#    #+#             */
/*   Updated: 2025/03/19 14:37:28 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void) {
	Zombie zombie;

	zombie.setName("Prueba");
	zombie.announce();

	randomChump("Probando");

	Zombie *newZombiePtr = newZombie("Zombie new");
	newZombiePtr->announce();

	delete newZombiePtr;

	return (0);
}