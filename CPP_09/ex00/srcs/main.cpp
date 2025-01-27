/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:20:52 by shinckel          #+#    #+#             */
/*   Updated: 2025/01/24 17:35:41 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/BitcoinExchange.hpp"

// outputs the value of a certain amount of bitcoin on a certain date
// this program must use a database in csv format, representing bitcoin price over time
// this program will take as input a second database, storing the different prices/dates to evaluate
// input file: each line must use the format "date | value"
// date format: Year-Month-Date
// valid value: it must be either a float or a positive integer, between 0 and 1000
// this program should display on the standard output the result of the value multiplied by the exchange rate
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    btc.mapData(argv[1]);
    return 0;
}