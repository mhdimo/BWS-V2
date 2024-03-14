#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <string>
#include "Player.hpp"
#include "Date.hpp"

std::vector<Player> parsePlayerData(const std::string& filename);
Date convertStringToDate(const std::string& dateStr);

#endif // PARSER_HPP
