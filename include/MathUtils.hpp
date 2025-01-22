#ifndef MATHUTILS_HPP
#define MATHUTILS_HPP

#include <vector>

/**
 * @brief Calculates the BWS rank for a player using dynamic weights.
 * 
 * This function computes the rank adjustment based on the number of badges,
 * the size of date arrays, and dynamically provided weights.
 * 
 * @param actualRank The current rank of the player.
 * @param noBadges The number of badges the player has.
 * @param sizeofArrayN1 Size of the array containing dates within 0 to 6 months difference.
 * @param sizeofArrayN2 Size of the array containing dates within 6 to 12 months difference.
 * @param sizeofArrayN3 Size of the array containing dates with more than 12 months difference.
 * @param weights A vector of weights used for rank calculation.
 * @return The calculated BWS rank for the player.
 */
int calculateBWSrankWithDynamicWeights(int actualRank, 
                                       int noBadges, 
                                       int sizeofArrayN1, 
                                       int sizeofArrayN2, 
                                       int sizeofArrayN3, 
                                       const std::vector<double>& weights) noexcept;

#endif // MATHUTILS_HPP
    