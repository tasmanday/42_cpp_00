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

Contact::Contact() : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}

void Contact::set_info()
{
	std::cout	<< std::endl
				<< BLUE "================== New Contact ==================" << std::endl
   				<< CYAN "     Enter First Name:     " BLUE "> " RESET;
    std::getline(std::cin, first_name);
    std::cout	<< CYAN "     Enter Last Name:      " BLUE "> " RESET;
    std::getline(std::cin, last_name);
    std::cout	<< CYAN "     Enter Nickame:        " BLUE "> " RESET;
    std::getline(std::cin, nickname);
    std::cout	<< CYAN "     Enter Phone Number:   " BLUE "> " RESET;
    std::getline(std::cin, phone_number);
    std::cout	<< CYAN "     Enter Darkest Secret: " BLUE "> " RESET;
    std::getline(std::cin, darkest_secret);
	std::cout	<< BLUE "=================================================" RESET << std::endl
				<< std::endl;
}

void wait(int seconds)
{
#ifdef _WIN32
    Sleep(seconds * 1000);  // Sleep for specified seconds (converted to milliseconds)
#else
    sleep(seconds);         // Sleep for specified seconds
#endif
}

void Contact::display_info() const
{
	int name_length = first_name.length() + last_name.length() + 3;
	int	line_length = (49 - name_length) / 2;

	std::cout << std::endl;

	if (line_length >= 0)
	{
		std::cout << BLUE;
		for (int i = 0; i < line_length; i++)
		{
			std::cout << "=";
		}

		std::cout <<  " " << first_name << " " << last_name << " ";

		for (int i = 0; i < line_length; i++)
		{
			std::cout << "=";
		}
		std::cout << RESET << std::endl;
	}
	else
		std::cout <<  BLUE << first_name << " " << last_name << RESET << std::endl;

	int first_length = first_name.length();
	if (first_length <= 30)
	{
		std::cout << BLUE "==   " CYAN << "First Name: " RESET << first_name;
		for (int i = 30 - first_length; i > 0; i--)
			std::cout << " ";
		std::cout << BLUE "==" RESET << std::endl;
	}
	else
		std::cout << BLUE "==   " CYAN << "First Name: " RESET << first_name << std::endl;
	
	int last_length = last_name.length();
	if (last_length <= 31)
	{
		std::cout << BLUE "==   " CYAN << "Last Name: " RESET << last_name;
		for (int i = 31 - last_length; i > 0; i--)
			std::cout << " ";
		std::cout << BLUE "==" RESET << std::endl;
	}
	else
		std::cout << BLUE "==   " CYAN << "Last Name: " RESET << last_name << std::endl;

	int nick_length = nickname.length();
	if (nick_length <= 33)
	{
		std::cout << BLUE "==   " CYAN << "Nickame: " RESET << nickname;
		for (int i = 33 - nick_length; i > 0; i--)
			std::cout << " ";
		std::cout << BLUE "==" RESET << std::endl;
	}
	else
		std::cout << BLUE "==   " CYAN << "Nickame: " RESET << nickname << std::endl;
	
	int phone_length = phone_number.length();
	if (phone_length <= 28)
	{
		std::cout << BLUE "==   " CYAN << "Phone Number: " RESET << phone_number;
		for (int i = 28 - phone_length; i > 0; i--)
			std::cout << " ";
		std::cout << BLUE "==" RESET << std::endl;
	}
	else
		std::cout << BLUE "==   " CYAN << "Phone Number: " RESET << phone_number << std::endl;

	int secret_length = darkest_secret.length();
	if (secret_length <= 26)
	{
		std::cout << BLUE "==   " CYAN << "Darkest Secret: " RESET << darkest_secret;
		for (int i = 26 - secret_length; i > 0; i--)
			std::cout << " ";
		std::cout << BLUE "==" RESET << std::endl;
	}
	else
		std::cout << BLUE "==   " CYAN << "Darkest Secret: " RESET << darkest_secret << std::endl;


	std::cout	<< BLUE "=================================================" RESET << std::endl
				<< std::endl;
	wait(5);
}

void print_centered(std::string text, int width)
{
    int padding = (width - text.length()) / 2;
    if (padding > 0)
        std::cout << std::setw(padding) << "" << text << std::setw(padding + (width - text.length()) % 2) << "";
	else if (text.length() == 9)
		std::cout << text << " ";
	else
        std::cout << text;
}

void Contact::display_summary(int index) const
{
	int width = 10;

    std::cout << BLUE "==|" RESET << "    " << index << "     " << BLUE "|" RESET;
    print_centered((first_name.length() > 9 ? first_name.substr(0, 9) + "." : first_name), width);
	std::cout << BLUE "|" RESET;
    print_centered((last_name.length() > 9 ? last_name.substr(0, 9) + "." : last_name), width);
	std::cout << BLUE "|" RESET;
    print_centered((nickname.length() > 9 ? nickname.substr(0, 9) + "." : nickname), width);
	std::cout << BLUE "|==" RESET << std::endl;
}

bool Contact::is_empty() const
{
    return first_name.empty() || last_name.empty() || nickname.empty() || phone_number.empty() || darkest_secret.empty();
}