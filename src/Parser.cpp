#include "../include/parser.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::vector<Player> parsePlayerData(const std::string& filename) {
    std::vector<Player> players;

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Impossibile aprire il file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string username, rank, numBadgesStr;
        std::getline(iss, username, ';');
        std::getline(iss, rank, ';');
        std::getline(iss, numBadgesStr, ';');

        double actualRank = std::stod(rank);
        int numBadges = std::stoi(numBadgesStr);

        Player player(username, actualRank, numBadges);

        for (int i = 0; i < numBadges; ++i) {
            std::string badgeDateStr;
            std::getline(iss, badgeDateStr, ';');

            Date badgeDate = convertStringToDate(badgeDateStr);
            player.addBadgeDate(badgeDate);
        }

        players.push_back(player);
    }

    file.close();
    return players;
}

Date convertStringToDate(const std::string& dateStr) {
    std::istringstream ss(dateStr);
    char delimiter;
    int day, month, year;

    ss >> day >> delimiter >> month >> delimiter >> year;

    if (ss.fail() || delimiter != '-' || day < 1 || day > 31 || month < 1 || month > 12 || year < 0) {
        throw std::runtime_error("Errore nella conversione della data: " + dateStr);
    }

    return Date(day, month, year);
}