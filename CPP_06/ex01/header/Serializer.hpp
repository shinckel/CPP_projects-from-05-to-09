/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:21:23 by shinckel          #+#    #+#             */
/*   Updated: 2025/01/01 20:24:54 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h> // uintptr_t

// static methods for converting a pointer to an unsigned integer type (uintptr_t) and vice versa
// how to ensure data integrity during serialization and deserialization
// serialization: Convert a pointer to uintptr_t.
// deserialization: Convert uintptr_t back to a pointer.
class Serializer {
  public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);

  private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer &clone);
    Serializer &operator=(const Serializer &clone);
};

#endif