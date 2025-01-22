#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "common.h"
#include "Date.hpp"

/**
 * @class Player
 * @brief A class to represent a player with username, actual rank, number of badges, and BWS rank.
 */
class Player {
public:
    /**
     * @brief Constructor to initialize a Player object.
     * @param username The username of the player.
     * @param actualRank The actual rank of the player.
     * @param numBadges The number of badges the player has.
     */
    Player(const std::string& username, long actualRank, int numBadges);

    /**
     * @brief Gets the username of the player.
     * @return The username of the player.
     */
    std::string getUsername() const;

    /**
     * @brief Gets the actual rank of the player.
     * @return The actual rank of the player.
     */
    long getActualRank() const;

    /**
     * @brief Gets the number of badges the player has.
     * @return The number of badges the player has.
     */
    int getNumBadges() const;

    /**
     * @brief Gets the badge dates of the player.
     * @return A const reference to a vector of Date objects representing the badge dates of the player.
     */
    const std::vector<Date>& getBadgeDates() const;

    /**
     * @brief Adds a badge date to the player's badge dates.
     * @param date The Date object representing the badge date to add.
     */
    void addBadgeDate(const Date& date);

    /**
     * @brief Sets the BWS rank of the player.
     * @param bwsRank The BWS rank to set for the player.
     */
    void setBWSRank(double bwsRank);

    /**
     * @brief Gets the BWS rank of the player.
     * @return The BWS rank of the player.
     */
    double getBWSRank() const;

private:
    std::string username;
    long actualRank;
    int numBadges;
    std::vector<Date> badgeDates;
    double bwsRank;
};

#endif // PLAYER_HPP
