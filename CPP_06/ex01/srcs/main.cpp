/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:21:21 by shinckel          #+#    #+#             */
/*   Updated: 2025/01/01 20:28:48 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Serializer.hpp"

int main() {
    Data originalData;
    originalData.id = 1;
    originalData.name = "Pesto";
    originalData.value = 42.0f;

    uintptr_t raw = Serializer::serialize(&originalData);
    Data* deserializedData = Serializer::deserialize(raw);

    // print the original and deserialized pointer addresses
    // preserve the original memory address of Data object
    std::cout << "Original pointer address: " << &originalData << std::endl;
    std::cout << "Deserialized pointer address: " << deserializedData << std::endl;

    if (deserializedData == &originalData) {
        std::cout << "\nID: " << deserializedData->id << std::endl;
        std::cout << "Name: " << deserializedData->name << std::endl;
        std::cout << "Value: " << deserializedData->value << std::endl;
        std::cout << "Serialization and deserialization successful!" << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

    return 0;
}

