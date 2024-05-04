/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:43:07 by tday              #+#    #+#             */
/*   Updated: 2024/05/04 13:43:07 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>	// cout, endl
#include <cctype>	// toupper

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j] != '\0'; j++)
				std::cout << (char)toupper(argv[i][j]);
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}