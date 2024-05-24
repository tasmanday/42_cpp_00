/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 00:48:08 by tday              #+#    #+#             */
/*   Updated: 2024/05/25 00:48:08 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

void Contact::setInfo()
{
    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkestSecret);
}

void Contact::displayInfo() const
{
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void Contact::displaySummary(int index) const
{
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << (firstName.length() > 9 ? firstName.substr(0, 9) + "." : firstName) << "|";
    std::cout << std::setw(10) << (lastName.length() > 9 ? lastName.substr(0, 9) + "." : lastName) << "|";
    std::cout << std::setw(10) << (nickname.length() > 9 ? nickname.substr(0, 9) + "." : nickname) << std::endl;
}

bool Contact::isEmpty() const
{
    return firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty();
}