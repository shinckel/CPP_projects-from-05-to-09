/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:42:43 by shinckel          #+#    #+#             */
/*   Updated: 2025/02/11 18:43:57 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
#define BASE_H

// randomly instanciates A, B or C, returns instance as a Base pointer
Base* generate(void);
//both functions print the actual type of the object pointed to by p: "A", "B" or "C"
void  identify(Base* p);
// however, using a pointer inside the function below is forbidden
void  identify(Base& p);
void  printBase(std::string str);

template <typename T>
bool pointerDynamicCast(Base& p);

#endif