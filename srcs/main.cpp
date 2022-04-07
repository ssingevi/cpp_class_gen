/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssingevi <ssingevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:02:44 by ssingevi          #+#    #+#             */
/*   Updated: 2022/03/26 20:17:18 by ssingevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StrReplace.hpp"
#include "define.hpp"

void ft_iter_toupper(std::string::iterator start, std::string::iterator end)
{
    std::string::iterator tmp;

    tmp = start;
    while (tmp < end)
    {
       *tmp = std::toupper(*tmp);
       tmp++;
    }
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: not enough arg" << std::endl;
		return (1);
	}
	std::string clname(av[1]);
	std::string str_hpp = clname + ".hpp";
	std::string str_cpp = clname + ".cpp";
	std::ofstream outfile_hpp(str_hpp.c_str());
	std::ofstream outfile_cpp(str_cpp.c_str());
	outfile_hpp << HPP_STR;
	outfile_cpp << CPP_STR;
	StrReplace str_replace_hpp(str_hpp, "Point", clname);
	StrReplace str_replace_cpp(str_cpp, "Point", clname);
	str_replace_hpp.replace();
	str_replace_cpp.replace();
	ft_iter_toupper(clname.begin(), clname.end());
	StrReplace str__hpp(str_hpp, "POINT", clname);
	str__hpp.replace();
}