#include "../include/Player.hpp"

Player::Player(const std::string& username, long actualRank, int numBadges)
    : username(username), actualRank(actualRank), numBadges(numBadges), bwsRank(0.0) {}

std::string Player::getUsername() const {
    return username;
}

long Player::getActualRank() const {
    return actualRank;
}

int Player::getNumBadges() const {
    return numBadges;
}

std::vector<Date> Player::getBadgeDates() const {
    return badgeDates;
}

void Player::addBadgeDate(const Date& date) {
    badgeDates.push_back(date);
}

void Player::setBWSRank(double bwsRank) {
    this->bwsRank = bwsRank;
}

long Player::getBWSRank() const {
    return bwsRank;
}
