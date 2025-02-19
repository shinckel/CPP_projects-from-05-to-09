/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:38:15 by shinckel          #+#    #+#             */
/*   Updated: 2025/02/19 18:39:53 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/whatever.hpp"

struct Data
{
	int content;
};

int main( void )
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "banana";
	std::string d = "abacate";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	int arr[5] = {10, 20, 30, 40, 50};
	int* ptr1 = &arr[1];
	int* ptr2 = &arr[4];

	// ::swap(ptr1, ptr2);
	std::cout << "ptr1 = " << ptr1 << ", ptr2 = " << ptr2 << std::endl;
	std::cout << "min( ptr1, ptr2 ) = " << ::min( ptr1, ptr2 ) << std::endl;
	std::cout << "max( ptr1, ptr2 ) = " << ::max( ptr1, ptr2 ) << std::endl;


	Data	*e = new Data; // dynamic memory allocation, pointer to data struct
	Data	*f = new Data;
	e->content = 5;
	f->content = 10;

	::swap(e, f);
	std::cout << "e = " << e->content << ", f = " << f->content << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

	delete e;
	delete f;

	return 0;
}