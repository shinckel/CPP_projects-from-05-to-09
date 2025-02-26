/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:03:51 by shinckel          #+#    #+#             */
/*   Updated: 2025/02/26 17:17:01 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Array.hpp"

struct People {
    std::string name;
    std::string bloodType;
    int         age;
};

int	main(void)
{
    // std::string is the type parameter passed to the Array template
	Array<std::string>  arrStr(3);
    try {
        std::cout << "array size: " << arrStr.size() << std::endl;
        arrStr[0] = "banana";
        std::cout << arrStr[0] << std::endl;
        arrStr[1] = "coconut";
        std::cout << arrStr[1] << std::endl;
        arrStr[2] = "grapes";
        std::cout << arrStr[2] << std::endl;
        arrStr[3] = "orange";
        std::cout << arrStr[3] << std::endl;
    } catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

    Array<People>   friends(3);
    try {
        People p1 = {"Hollie", "A+", 6};
        People p2 = {"Dani", "B-", 37};
        People p3 = {"Zuca", "B-", 38};
        friends[0] = p1;
        friends[1] = p2;
        friends[2] = p3;

        Array<People> family = friends;
        People p4 = {"Nicho", "A+", 31};
        People p5 = {"Sara", "B-", 52};
        People p6 = {"José", "B-", 59};
        family[1] = p4;
        family[2] = p5;
        std::cout << "———————————————————————" << std::endl;
        for (unsigned int i = 0; i < friends.size(); ++i) {
        std::cout << "Family " << i << ": " << family[i].name << ", " 
                  << family[i].bloodType << ", " << family[i].age << std::endl;
        }
        // changing cloned obj shouldn't affect original
        std::cout << "———————————————————————" << std::endl;
        for (unsigned int i = 0; i < friends.size(); ++i) {
        std::cout << "Friend " << i << ": " << friends[i].name << ", " 
                  << friends[i].bloodType << ", " << friends[i].age << std::endl;
        }
        // operator overload [] throws OutOfBounds exception
        family[3] = p6;
    } catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

    Array<People> tempFamily(3);
    People p7 = {"Dorina", "A+", 60};
    People p8 = {"Martha", "B-", 38};
    People p9 = {"Maria", "B+", 29};
    tempFamily[0] = p7;
    tempFamily[1] = p8;
    tempFamily[2] = p9;
    const Array<People> constFamily = tempFamily;
    try {
        std::cout << "———————————————————————" << std::endl;
        for (unsigned int i = 0; i < constFamily.size(); ++i) {
            std::cout << "Const Family " << i << ": " << constFamily[i].name << ", " 
                      << constFamily[i].bloodType << ", " << constFamily[i].age << std::endl;
        }
        // operator overload [] throws OutOfBounds exception
        std::cout << constFamily[3].name << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }