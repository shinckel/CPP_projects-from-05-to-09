/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:54:11 by shinckel          #+#    #+#             */
/*   Updated: 2024/11/08 15:54:46 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
# define COLORS_HPP 

# include <iostream>

// namespace and friend are forbidden in this project
// namespace Color {
//     enum Code {
//         FG_RED      = 31,
//         FG_GREEN    = 32,
//         FG_YELLOW   = 33,
//         FG_BLUE     = 34,
//         FG_PURPLE   = 35,
//         FG_L_BLUE   = 36,
//         FG_DEFAULT  = 39,
//         BG_RED      = 41,
//         BG_GREEN    = 42,
//         BG_BLUE     = 44,
//         BG_DEFAULT  = 49
//     };
//     class Modifier {
//         Code code;
//     public:
//         Modifier(Code pCode) : code(pCode) {}
//         friend std::ostream&
//         operator<<(std::ostream& os, const Modifier& mod) {
//             return os << "\033[" << mod.code << "m";
//         }
//     };
// }

class Color {
public:
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_YELLOW   = 33,
        FG_BLUE     = 34,
        FG_PURPLE   = 35,
        FG_L_BLUE   = 36,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };

    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        Code getCode() const { return code; }
    };

    // Member function to apply color modifier to output stream
    static std::ostream& modify(std::ostream& os, const Modifier& mod) {
        return os << "\033[" << mod.getCode() << "m";
    }
};

// Overloaded << operator to apply color modifier using Color::modify
inline std::ostream& operator<<(std::ostream& os, const Color::Modifier& mod) {
    return Color::modify(os, mod);
}

#endif
