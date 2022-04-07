/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StrReplace.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssingevi <ssingevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:27:55 by ssingevi          #+#    #+#             */
/*   Updated: 2022/03/26 21:17:37 by ssingevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StrReplace.hpp"

StrReplace::StrReplace(std::string filename, std::string strtoreplace, std::string remplacementstr)
{
	this->filename = filename;
	this->file.open(filename.c_str());
	this->strtoreplace = strtoreplace;
	this->remplacementstr = remplacementstr;
}

StrReplace::StrReplace(void)
{
}

StrReplace::~StrReplace(void)
{
}

void	StrReplace::setstrtoreplace(std::string strtoreplace)
{
	this->strtoreplace = strtoreplace;
}

void	StrReplace::setreplacementstr(std::string remplacementstr)
{
	this->remplacementstr = remplacementstr;
}

void	StrReplace::setfile(std::string filename)
{
	if (this->file.is_open())
		this->file.close();
	this->filename = filename;
	this->file.open(filename.c_str(), std::ifstream::in);
}

bool	StrReplace::check(void)
{
	bool ret = true;

	if (this->filename.empty())
	{
		std::cerr << "Error : filename is empty" << std::endl;
		ret = false;
	}
	if (this->strtoreplace.empty())
	{
		std::cerr << "Error : str to replace is empty" << std::endl;
		ret = false;
	}
	if (!this->file.good())
	{
		std::cout << this->filename << std::endl;
		std::cerr << "Error : filename is not valid" << std::endl;
		ret = false;
	}
	return (ret);
}

std::string		StrReplace::getoutfilename(void)
{
	return(this->filename);
}

void	StrReplace::replace(void)
{
	if (!StrReplace::check())
		return ;
	this->filecontent.assign(std::istreambuf_iterator<char>(this->file), std::istreambuf_iterator<char>());
	for (size_t i = 0; i < this->filecontent.size(); i++)
	{
		if (!this->filecontent.compare(i, this->strtoreplace.size(), this->strtoreplace))
		{
			this->filecontent.erase(i,  this->strtoreplace.size());
			this->filecontent.insert(i, this->remplacementstr);
			i+= this->remplacementstr.size() - 1;
		}
	}
	std::ofstream outfile(StrReplace::getoutfilename().c_str());
	outfile << this->filecontent;
}
