#ifndef MATHUTILS_HPP
#define MATHUTILS_HPP
#include <cmath>
#include <vector>

/**
 * @brief Calculates the BWS rank for a player based on their actual rank, number of badges, and the size of three date arrays.
 * @param actualRank The actual rank of the player.
 * @param noBadges The number of badges the player has.
 * @param sizeofArrayN1 The size of the array containing dates within 0 to 6 months difference.
 * @param sizeofArrayN2 The size of the array containing dates within 6 to 12 months difference.
 * @param sizeofArrayN3 The size of the array containing dates with more than 12 months difference.
 * @return The calculated BWS rank for the player.
 */
int calculateBWSrank(int actualRank, int noBadges, int sizeofArrayN1, int sizeofArrayN2, int sizeofArrayN3);

/**
 * @brief Calculates the BWS rank for a player using dynamic weights.
 * @param actualRank The actual rank of the player.
 * @param noBadges The number of badges the player has.
 * @param sizeofArrayN1 The size of the array containing dates within 0 to 6 months difference.
 * @param sizeofArrayN2 The size of the array containing dates within 6 to 12 months difference.
 * @param sizeofArrayN3 The size of the array containing dates with more than 12 months difference.
 * @return The calculated BWS rank for the player using dynamic weights.
 */
int calculateBWSrankWithDynamicWeights(int actualRank, int noBadges, int sizeofArrayN1, int sizeofArrayN2, int sizeofArrayN3, const std::vector<double>& weights);

#endif // MATHUTILS_HPP
