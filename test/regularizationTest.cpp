// Copyright (c) 2018 Grumpy Cat Software S.L.
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <tsa/regularization.h>
#include <tsa/statistics.h>
#include "tsaTest.h"

void groupBySingleKeyColumn() {
    float data[] = {0, 1, 1, 2, 2, 3, 0, 3, 3, 1, 1, 2};
    af::array tss = af::array(6, 2, data);

    float expected[] = {0, 3, 1, 2};

    float *result = tsa::regularization::groupBy(tss, af::mean).host<float>();

    for (int i = 0; i < 4; i++) {
        ASSERT_EQ(result[i], expected[i]);
    }
}

void groupByDoubleKeyColumn() {
    float data[] = {0, 1, 1, 2, 2, 3, 1, 2, 2, 3, 3, 4, 0, 3, 3, 1, 1, 2};
    af::array tss = af::array(6, 3, data);

    float expected[] = {0, 3, 1, 2};

    float *result = tsa::regularization::groupBy(tss, af::mean, 2).host<float>();

    for (int i = 0; i < 4; i++) {
        ASSERT_EQ(result[i], expected[i]);
    }
}

void groupByDoubleKeyColumn2() {
    float data[] = {0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 2, 3, 4, 5};
    af::array tss = af::array(5, 3, data);

    float expected[] = {1, 2, 3.5, 5};

    float *result = tsa::regularization::groupBy(tss, af::mean, 2).host<float>();

    for (int i = 0; i < 4; i++) {
        ASSERT_EQ(result[i], expected[i]);
    }
}

void groupByDoubleKeyDoubleValueColumn() {
    float data[] = {0, 1, 2, 3, 4, 5};
    af::array tss = af::array(6, data);

    af::array input = af::constant(0, tss.dims(0) - 1, 4, tss.type());

    input(span, af::seq(2)) += tsa::statistics::quantilesCut(tss(af::seq(5)), 2);
    input(span, 2) += tss(af::seq(5));
    input(span, 3) += af::diff1(tss, 0);

    float expected[] = {1, 3.5, 1, 1};

    float *result = tsa::regularization::groupBy(input, af::mean, 2, 2).host<float>();

    for (int i = 0; i < 4; i++) {
        ASSERT_NEAR(result[i], expected[i], EPSILON);
    }
}

// Testing only in the first available device
TSA_TEST_BACKENDS(RegularizationTests, GroupBySingleKeyColumn, groupBySingleKeyColumn, true, true, true, false, false,
                  false);
TSA_TEST_BACKENDS(RegularizationTests, GroupByDoubleKeyColumn, groupByDoubleKeyColumn, true, true, true, false, false,
                  false);
TSA_TEST_BACKENDS(RegularizationTests, GroupByDoubleKeyColumn2, groupByDoubleKeyColumn2, true, true, true, false, false,
                  false);
TSA_TEST_BACKENDS(RegularizationTests, GroupByDoubleKeyDoubleValueColumn, groupByDoubleKeyDoubleValueColumn, true, true,
                  true, false, false, false);