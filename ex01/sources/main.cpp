/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:15:11 by tday              #+#    #+#             */
/*   Updated: 2024/05/25 23:15:11 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"
#include <cctype>    // std::toupper

void makeUpper(std::string &str)
{
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = std::toupper(static_cast<unsigned char>(str[i]));
    }
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
	{
        phoneBook.print_menu();
        std::getline(std::cin, command);
		makeUpper(command);
        if (command == "ADD")
            phoneBook.add_contact();
        else if (command == "SEARCH")
            phoneBook.search();
        else if (command == "EXIT")
            break;
        else
            std::cout 	<< RED "Invalid command!" << std::endl
						<< std::endl;
    }
    return (0);
}
