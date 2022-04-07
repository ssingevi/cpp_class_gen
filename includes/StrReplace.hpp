/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StrReplace.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssingevi <ssingevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:20:47 by ssingevi          #+#    #+#             */
/*   Updated: 2022/03/26 20:54:56 by ssingevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRRPLACE_HPP
# define STRRPLACE_HPP

#include <string>
#include <iostream>
#include <fstream>

class	StrReplace
{
	public:
		StrReplace(std::string filename, std::string strtoreplace, std::string remplacementstr);
		StrReplace(void);
		~StrReplace(void);

		void	setstrtoreplace(std::string strtoreplace);
		void	setreplacementstr(std::string remplacementstr);
		void	setfile(std::string filename);
		void	replace(void);

	private:
		std::string		getoutfilename(void);
		bool			check(void);

		std::ifstream	file;
		std::string		filename;
		std::string		strtoreplace;
		std::string		remplacementstr;
		std::string		filecontent;
		// std::string		fileoutpout;
};

#endif
