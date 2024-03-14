#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include "Date.hpp"

class Player {
public:
    Player(const std::string& username, long actualRank, int numBadges);
    std::string getUsername() const;
    long getActualRank() const;
    int getNumBadges() const;
    std::vector<Date> getBadgeDates() const; // Obtain the badge dates
    void addBadgeDate(const Date& date); // Add a badge date to the vector
    void setBWSRank(double bwsRank); // Method to set the BWS rank
    long getBWSRank() const; // Method to get the BWS rank

private:
    std::string username;
    long actualRank;
    int numBadges;
    std::vector<Date> badgeDates;
    long bwsRank;
};

#endif // PLAYER_HPP
