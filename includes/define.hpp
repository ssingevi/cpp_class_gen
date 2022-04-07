/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssingevi <ssingevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:05:37 by ssingevi          #+#    #+#             */
/*   Updated: 2022/04/07 14:37:11 by ssingevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(DEFINE)
#define DEFINE
#define HPP_STR "#ifndef POINT_HPP" << std::endl << "# define POINT_HPP" << std::endl << "class Point" << std::endl << "{" << std::endl << "    public:" << std::endl << "        Point(void);" << std::endl << "        Point(Point const &pt);" << std::endl << "        ~Point();" << std::endl << "        Point &operator=(Point &pt);" << std::endl << "    private:" << std::endl << "};" << std::endl << "#endif"<< std::endl 
#define CPP_STR "#include \"Point.hpp\""<<  std::endl<<  std::endl<< "Point::Point(void)"<<  std::endl<< "{"<<  std::endl<< "}"<<  std::endl <<  std::endl<< "Point::Point(Point const &pt)"<<  std::endl<< "{"<<  std::endl<< "}"<<  std::endl <<  std::endl<< "Point &Point::operator=(Point &pt)"<<  std::endl<< "{"<<  std::endl<< "}"<<  std::endl <<  std::endl<< "Point::~Point()"<<  std::endl<< "{"<<  std::endl<< "}"<<  std::endl <<  std::endl
#endif
