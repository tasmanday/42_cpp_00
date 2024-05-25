/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:09:33 by tday              #+#    #+#             */
/*   Updated: 2024/05/05 18:58:22 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <limits>

class PhoneBook
{
public:
    PhoneBook();
	void print_menu();
    void add_contact();
    void search() const;

private:
    Contact contacts[8];
    int oldest_index;
};

#endif
