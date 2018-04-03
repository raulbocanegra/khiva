// Copyright (c) 2018 Grumpy Cat Software S.L.
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <tsa/polynomial.h>
#include "tsaTest.h"

void polyfit1() {
    float data[] = {0, 1, 2, 3, 4, 5};
    af::array x = af::array(6, data);

    float *calculated = tsa::polynomial::polyfit(x, x, 1).host<float>();

    float expected[] = {1.0, 0.0};

    ASSERT_NEAR(calculated[0], expected[0], EPSILON);
    ASSERT_NEAR(calculated[1], expected[1], EPSILON);
}

void polyfit3() {
    float dataX[] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
    af::array x = af::array(6, dataX);

    float dataY[] = {0.0, 0.8, 0.9, 0.1, -0.8, -1.0};
    af::array y = af::array(6, dataY);

    float *calculated = tsa::polynomial::polyfit(x, y, 3).host<float>();

    float expected[] = {0.08703704, -0.81349206, 1.69312169, -0.03968254};

    for (int i = 0; i < 4; i++) {
        ASSERT_NEAR(calculated[i], expected[i], EPSILON * 3);
    }
}

// Not testing in CPU because the static linking of OpenMP that Arrayfire does makes the test crash
TSA_TEST_BACKENDS(PolynomialTests, Polyfit1, polyfit1, true, true, false, true, true, false);
TSA_TEST_BACKENDS(PolynomialTests, Polyfit3, polyfit3, true, true, false, true, true, false);