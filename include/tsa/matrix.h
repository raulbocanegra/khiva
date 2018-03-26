// Copyright (c) 2018 Grumpy Cat Software S.L.
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <arrayfire.h>

using namespace af;

namespace tsa {

namespace matrix {
/**
 * @brief Calculates the sliding dot product of the time series 'q' against t
 *
 * @param q Array whose first dimension is the length of the query time series
 * and the last dimension is the number of time series to calculate
 * @param t Array with the second time series in the first dimension
 * @return array Returns an array with as many elements as 't' in the first dimension
 * and as many elements as the last dimension of 'q' in the last dimension
 */
af::array slidingDotProduct(af::array q, af::array t);

/**
 * @brief Calculates the moving average and standard deviation of the time series 't'.
 *
 * @param t Input time series. Multiple time series
 * @param a Auxiliary array to be used in the function calculateDistanceProfile. Use
 * the overloaded method without this parameter
 * @param m Window size
 * @param mean Output array containing the moving average
 * @param stdev Output array containing the moving standard deviation
 */
void meanStdev(af::array t, af::array &a, long m, af::array &mean, af::array &stdev);

/**
 * @brief Calculates the moving average and standard deviation of the time series 't'.
 *
 * @param t Input time series. Multiple time series
 * @param m Window size
 * @param mean Output array containing the moving average
 * @param stdev Output array containing the moving standard deviation
 */
void meanStdev(af::array t, long m, af::array &mean, af::array &stdev);

/**
 * @brief Function to generate a band matrix of batchSizeXtsLength with the offset batchStart
 *
 * @param m Subsequence length used to generate a band of m/2 at each side
 * @param batchSize Size of the first dimension
 * @param batchStart Offset of the band matrix
 * @param tsLength Size of the second dimension of the matrix
 * @param nTimeSeries Number of time series to generate the mask for
 * @return af::array
 */
af::array generateMask(long m, long batchSize, long batchStart, long tsLength, long nTimeSeries = 1);

/**
 * @brief Calculates the distance between 'q' and the time series 't', which produced the sliding. Multiple queries can
 * be computed simultaneously in the last dimension of 'q'.
 * @param m Subsequence length (required to mask the minimum m/2 positions left and right in case ignoreTrivial is true)
 * @param qt The sliding dot product of 'q' and 't'
 * @param a Auxiliary array computed using the meanStdev function. This array contains a
 * precomputed fixed value to speed up the distance calculation
 * @param sum_q Sum of the values contained in 'q'
 * @param sum_q2 Sum of squaring the values contained in 'q'
 * @param mean_t Moving average of 't' using a window size equal to the number of elements
 * in 'q'
 * @param sigma_t Moving standard deviation of 't' using a window size equal to the number of elements
 * in 'q'
 * @param mask Mask band matrix to filter the trivial match of a subsequence with itself
 * @param distance Resulting minimal distance
 * @param index Position where the minimum is occurring
 * @param batchStart Indicates where the currently computed batch starts. Defaults to 0 for the parallel case. The
 * parameter is used to determine the mask for the trivial matches.
 */
void calculateDistanceProfile(long m, af::array qt, af::array a, af::array sum_q, af::array sum_q2, af::array mean_t,
                              af::array sigma_t, af::array mask, af::array &distance, af::array &index);

/**
 * @brief Calculates the distance between 'q' and the time series 't', which produced the sliding. Multiple queries can
 * be computed simultaneously in the last dimension of 'q'.
 * @param m Subsequence length (required to mask the minimum m/2 positions left and right in case ignoreTrivial is true)
 * @param qt The sliding dot product of 'q' and 't'
 * @param a Auxiliary array computed using the meanStdev function. This array contains a
 * precomputed fixed value to speed up the distance calculation
 * @param sum_q Sum of the values contained in 'q'
 * @param sum_q2 Sum of squaring the values contained in 'q'
 * @param mean_t Moving average of 't' using a window size equal to the number of elements
 * in 'q'
 * @param sigma_t Moving standard deviation of 't' using a window size equal to the number of elements
 * in 'q'
 * @param distance Resulting minimal distance
 * @param index Position where the minimum is occurring
 */
void calculateDistanceProfile(long m, af::array qt, af::array a, af::array sum_q, af::array sum_q2, af::array mean_t,
                              af::array sigma_t, af::array &distance, af::array &index);

/**
 * @brief
 *
 * @param q Array whose first dimension is the length of the query time series
 * and the last dimension is the number of time series to calculate
 * @param t Array with the second time series in the first dimension
 * @param m Subsequence length (required to mask the minimum m/2 positions left and right in case ignoreTrivial is true)
 * @param a Auxiliary array computed using the meanStdev function. This array contains a
 * precomputed fixed value to speed up the distance calculation
 * * @param mean_t Moving average of 't' using a window size equal to the number of elements
 * in 'q'
 * @param sigma_t Moving standard deviation of 't' using a window size equal to the number of elements
 * in 'q'
 * @param ignoreTrivial Boolean value that indicates whether the function should consider the trivial match of
 * a subsequence with itself or not
 * @param distance Resulting minimal distance
 * @param index Position where the minimum is occurring
 */
void mass(af::array q, af::array t, long m, af::array a, af::array mean_t, af::array sigma_t, af::array mask,
          af::array &distance, af::array &index);

/**
 * @brief
 *
 * @param q Array whose first dimension is the length of the query time series
 * and the last dimension is the number of time series to calculate
 * @param t Array with the second time series in the first dimension
 * @param m Subsequence length (required to mask the minimum m/2 positions left and right in case ignoreTrivial is true)
 * @param a Auxiliary array computed using the meanStdev function. This array contains a
 * precomputed fixed value to speed up the distance calculation
 * * @param mean_t Moving average of 't' using a window size equal to the number of elements
 * in 'q'
 * @param sigma_t Moving standard deviation of 't' using a window size equal to the number of elements
 * in 'q'
 * @param distance Resulting minimal distance
 * @param index Position where the minimum is occurring
 */
void mass(af::array q, af::array t, long m, af::array a, af::array mean_t, af::array sigma_t, af::array &distance,
          af::array &index);

/**
 * @brief STAMP algorithm to calculate the matrix profile between 'ta' and 'tb' using a subsequence length
 * of 'm'
 *
 * @param ta Query time series
 * @param tb Reference time series
 * @param m Subsequence length
 * @param profile The matrix profile, which reflects the distance to the closer element of the subsequence
 * from 'ta' in 'tb'
 * @param index The matrix profile index, which points to where the previously mentioned minimum is located
 */
void stomp(af::array ta, af::array tb, long m, af::array &profile, af::array &index);

/**
 * @brief STAMP algorithm to calculate the matrix profile between 't' and itself using a subsequence length
 * of 'm'. This method filters the trivial matches.
 *
 * @param t Query and reference time series
 * @param m Subsequence length
 * @param profile The matrix profile, which reflects the distance to the closer element of the subsequence
 * from 't' in a different location of itself
 * @param index The matrix profile index, which points to where the previously mentioned minimum is located
 */
void stomp(af::array t, long m, af::array &profile, af::array &index);

/**
 * @brief This function extracts the best N motifs from a previously calculated matrix profile
 *
 * @param profile The matrix profile containing the minimum distance of each subsequence
 * @param index The matrix profile index containing where each minimum occurs
 * @param n Number of motifs to extract
 * @param motifs The distance of the best N motifs
 * @param motifsIndices The indices of the best N motifs
 * @param subsequenceIndices The indices of the query sequences that produced the minimum reported in the motifs
 * output array
 */
void findBestNMotifs(af::array profile, af::array index, long n, af::array &motifs, af::array &motifsIndices,
                     af::array &subsequenceIndices);

/**
 * @brief This function extracts the best N discords from a previously calculated matrix profile
 *
 * @param profile The matrix profile containing the minimum distance of each subsequence
 * @param index The matrix profile index containing where each minimum occurs
 * @param n Number of discords to extract
 * @param discords The distance of the best N discords
 * @param discordIndices The indices of the best N discords
 * @param subsequenceIndices The indices of the query sequences that produced the discords reported in the discords
 * output array
 */
void findBestNDiscords(af::array profile, af::array index, long n, af::array &discords, af::array &discordsIndices,
                       af::array &subsequenceIndices);
};  // namespace matrix
};  // namespace tsa