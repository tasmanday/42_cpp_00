/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:15:00 by tday              #+#    #+#             */
/*   Updated: 2024/05/25 23:15:00 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"

PhoneBook::PhoneBook() : oldest_index(0) {}

void PhoneBook::print_menu()
{
  std::cout	<< BLUE "=================== Phonebook ===================" << std::endl
			<< "==                                             ==" << std::endl
			<< "==       " CYAN "ADD" RESET"    - Add a new contact.           " BLUE "==" << std::endl
			<< "==       " CYAN "SEARCH" RESET" - Display contact info.        " BLUE "==" << std::endl
			<< "==       " CYAN "EXIT" RESET"   - Exit phonebook.              " BLUE "==" << std::endl
			<< "==                                             ==" << std::endl
			<< "=================================================" << std::endl
			<< "> " RESET;
}

void PhoneBook::add_contact()
{
    Contact newContact;
    newContact.set_info();

    if (!newContact.is_empty())
	{
        contacts[oldest_index] = newContact;
        oldest_index = (oldest_index + 1) % 8;
    }
	else
        std::cout << "Contact information incomplete, not added to phonebook." << std::endl;
}

void PhoneBook::search() const
{
	int width = 10;

	std::cout	<< std::endl
				<< BLUE "=================== Contacts ====================" << std::endl
				<< "==                                             ==" << std::endl
				<< "==" CYAN "   Enter the index to view contact details   " BLUE "==" << std::endl
				<< "==                                             ==" << std::endl
				<< "==|-------------------------------------------|==" << std::endl
				<< "==|" RESET;
    print_centered("Index", width);
	std::cout 	<< BLUE "|" RESET;
	print_centered("First Name", width);
	std::cout 	<< BLUE "|" RESET;
	std::cout 	<< "Last Name ";
	std::cout 	<< BLUE "|" RESET;
	print_centered("Nickname", width);
    std::cout	<< BLUE "|==" << std::endl
    			<< "==|-------------------------------------------|==" RESET << std::endl;

    for (int i = 0; i < 8; ++i)
	{
        if (!contacts[i].is_empty())
            contacts[i].display_summary(i);
    }

	std::cout	<< BLUE "=================================================" << std::endl
				<< "> " RESET;

    int index;
   	if (!(std::cin >> index))
	{
        std::cin.clear();  // Clear the error flag on std::cin
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the rest of the invalid input
        std::cout << RED "Invalid input. Please enter a valid integer." RESET << std::endl << std::endl;
		return;
    }
	else
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer
        if (index >= 0 && index < 8 && !contacts[index].is_empty())
            contacts[index].display_info();
        else
            std::cout << RED "Invalid index or contact is empty." RESET << std::endl << std::endl;
    }
}
