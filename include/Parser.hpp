#ifndef PARSER_HPP
#define PARSER_HPP

#include "common.h"
#include "Player.hpp"
#include "Date.hpp"

/**
 * @brief Parses player data from a file.
 * @param filename The name of the file containing player data.
 * @return A vector of Player objects parsed from the file.
 */
std::vector<Player> parsePlayerData(const std::string& filename);

/**
 * @brief Converts a date string to a Date object.
 * @param dateStr The date string to convert.
 * @return A Date object representing the converted date.
 */
Date convertStringToDate(const std::string& dateStr);

#endif // PARSER_HPP
