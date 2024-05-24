/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:10:15 by tday              #+#    #+#             */
/*   Updated: 2024/05/25 01:24:23 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

/* libraries */
#include <iostream>	// std::cout, std::cin, std::endl
#include <string>	// std::string

/* colours */
# define RESET	"\033[0m"
# define GRAY	"\033[1;30m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define MGNTA	"\033[1;35m"
# define CYAN	"\033[1;36m"
# define WHITE	"\033[1;37m"

/* class */
class Contact
{
	public:
		Contact();
		void setInfo();
		void displayInfo() const;
		void displaySummary(int index) const;
		bool isEmpty() const;
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif