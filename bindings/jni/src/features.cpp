// Copyright (c) 2018 Grumpy Cat Software S.L.
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <jni.h>
#include <tsa/features.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jlongArray JNICALL Java_tsa_Features_absEnergy(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::absEnergy(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);
    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_absoluteSumOfChanges(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::absoluteSumOfChanges(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);
    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_aggregatedAutocorrelation(JNIEnv *env, jobject thisObj, jlong ref,
                                                                         jint aggregationFunction) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    switch (aggregationFunction) {
        case 0:
            af_retain_array(&af_p, tsa::features::aggregatedAutocorrelation(var, af::mean).get());
            break;
        case 1:
            af_retain_array(&af_p, tsa::features::aggregatedAutocorrelation(var, af::median).get());
            break;
        case 2:
            af_retain_array(&af_p, tsa::features::aggregatedAutocorrelation(var, af::min).get());

            break;
        case 3:
            af_retain_array(&af_p, tsa::features::aggregatedAutocorrelation(var, af::max).get());

            break;
        case 4:
            af_retain_array(&af_p, tsa::features::aggregatedAutocorrelation(var, af::stdev).get());

            break;
        case 5:
            af_retain_array(&af_p, tsa::features::aggregatedAutocorrelation(var, af::var).get());

            break;
        default:
            af_retain_array(&af_p, tsa::features::aggregatedAutocorrelation(var, af::mean).get());

            break;
    }
    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);
    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_aggregatedLinearTrend(JNIEnv *env, jobject thisObj, jlong ref,
                                                                     jlong chunkSize, jint aggregationFunction) {
    jint l = 6;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer_slope = 0;
    af_array af_p_slope = (af_array)raw_pointer_slope;

    jlong raw_pointer_intercept = 0;
    af_array af_p_intercept = (af_array)raw_pointer_intercept;

    jlong raw_pointer_rvalue = 0;
    af_array af_p_rvalue = (af_array)raw_pointer_rvalue;

    jlong raw_pointer_pvalue = 0;
    af_array af_p_pvalue = (af_array)raw_pointer_pvalue;

    jlong raw_pointer_stderrest = 0;
    af_array af_p_stderrest = (af_array)raw_pointer_stderrest;

    af_retain_array(&arr, var.get());

    af::array primitive_slope;
    af::array primitive_intercept;
    af::array primitive_rvalue;
    af::array primitive_pvalue;
    af::array primitive_stderrest;
    switch (aggregationFunction) {
        case 0:
            tsa::features::aggregatedLinearTrend(var, chunkSize, af::mean, primitive_slope, primitive_intercept,
                                                 primitive_rvalue, primitive_pvalue, primitive_stderrest);
            break;
        case 1:
            tsa::features::aggregatedLinearTrend(var, chunkSize, af::median, primitive_slope, primitive_intercept,
                                                 primitive_rvalue, primitive_pvalue, primitive_stderrest);
            break;
        case 2:
            tsa::features::aggregatedLinearTrend(var, chunkSize, af::min, primitive_slope, primitive_intercept,
                                                 primitive_rvalue, primitive_pvalue, primitive_stderrest);
            break;
        case 3:
            tsa::features::aggregatedLinearTrend(var, chunkSize, af::max, primitive_slope, primitive_intercept,
                                                 primitive_rvalue, primitive_pvalue, primitive_stderrest);
            break;
        case 4:
            tsa::features::aggregatedLinearTrend(var, chunkSize, af::stdev, primitive_slope, primitive_intercept,
                                                 primitive_rvalue, primitive_pvalue, primitive_stderrest);
            break;
        default:
            tsa::features::aggregatedLinearTrend(var, chunkSize, af::mean, primitive_slope, primitive_intercept,
                                                 primitive_rvalue, primitive_pvalue, primitive_stderrest);
            break;
    }
    af_retain_array(&af_p_slope, primitive_slope.get());
    af_retain_array(&af_p_intercept, primitive_intercept.get());
    af_retain_array(&af_p_rvalue, primitive_rvalue.get());
    af_retain_array(&af_p_pvalue, primitive_pvalue.get());
    af_retain_array(&af_p_stderrest, primitive_stderrest.get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p_slope;
    tmp[2] = (jlong)af_p_intercept;
    tmp[3] = (jlong)af_p_rvalue;
    tmp[4] = (jlong)af_p_pvalue;
    tmp[5] = (jlong)af_p_stderrest;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);
    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_approximateEntropy(JNIEnv *env, jobject thisObj, jlong ref, jint m,
                                                                  jfloat r) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::approximateEntropy(var, m, r).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);
    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_crossCovariance(JNIEnv *env, jobject thisObj, jlong ref_xss,
                                                               jlong ref_yss, jboolean unbiased) {
    jint l = 3;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr_xss = (af_array)ref_xss;
    af::array var_xss = af::array(arr_xss);

    af_retain_array(&arr_xss, var_xss.get());

    af_array arr_yss = (af_array)ref_yss;
    af::array var_yss = af::array(arr_yss);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&af_p, tsa::features::crossCovariance(var_xss, var_yss, unbiased).get());

    tmp[0] = (jlong)arr_xss;
    tmp[1] = (jlong)arr_yss;
    tmp[2] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);
    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_autoCovariance(JNIEnv *env, jobject thisObj, jlong ref,
                                                              jboolean unbiased) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::autoCovariance(var, unbiased).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_crossCorrelation(JNIEnv *env, jobject thisObj, jlong ref_xss,
                                                                jlong ref_yss, jboolean unbiased) {
    jint l = 3;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr_xss = (af_array)ref_xss;
    af::array var_xss = af::array(arr_xss);

    af_retain_array(&arr_xss, var_xss.get());

    af_array arr_yss = (af_array)ref_yss;
    af::array var_yss = af::array(arr_yss);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&af_p, tsa::features::crossCorrelation(var_xss, var_yss, unbiased).get());

    tmp[0] = (jlong)arr_xss;
    tmp[1] = (jlong)arr_yss;
    tmp[2] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);
    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_autoCorrelation(JNIEnv *env, jobject thisObj, jlong ref, jlong maxLag,
                                                               jboolean unbiased) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::autoCorrelation(var, maxLag, unbiased).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_binnedEntropy(JNIEnv *env, jobject thisObj, jlong ref, jint max_bins) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::binnedEntropy(var, max_bins).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_c3(JNIEnv *env, jobject thisObj, jlong ref, jlong lag) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::c3(var, lag).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_cidCe(JNIEnv *env, jobject thisObj, jlong ref, jboolean zNormalize) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::cidCe(var, zNormalize).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_countAboveMean(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::countAboveMean(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_countBelowMean(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::countBelowMean(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_cwtCoefficients(JNIEnv *env, jobject thisObj, jlong ref, jlong widths,
                                                               jint coeff, jint w) {
    jint l = 3;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    af_array af_w = (af_array)widths;
    af::array var_w = af::array(af_w);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_w, var_w.get());

    af_retain_array(&af_p, tsa::features::cwtCoefficients(var, var_w, coeff, w).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_w;
    tmp[2] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_energyRatioByChunks(JNIEnv *env, jobject thisObj, jlong ref,
                                                                   jlong numSegments, jlong segmentFocus) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::energyRatioByChunks(var, numSegments, segmentFocus).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_fftAggregated(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::fftAggregated(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_fftCoefficient(JNIEnv *env, jobject thisObj, jlong ref,
                                                              jlong coefficient) {
    jint l = 5;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer_real = 0;
    af_array af_p_real = (af_array)raw_pointer_real;

    jlong raw_pointer_imag = 0;
    af_array af_p_imag = (af_array)raw_pointer_imag;

    jlong raw_pointer_absolute = 0;
    af_array af_p_absolute = (af_array)raw_pointer_absolute;

    jlong raw_pointer_angle = 0;
    af_array af_p_angle = (af_array)raw_pointer_angle;

    af_retain_array(&arr, var.get());

    af::array primitive_real;
    af::array primitive_imag;
    af::array primitive_absolute;
    af::array primitive_angle;

    tsa::features::fftCoefficient(var, coefficient, primitive_real, primitive_imag, primitive_absolute,
                                  primitive_angle);

    af_retain_array(&af_p_real, primitive_real.get());
    af_retain_array(&af_p_imag, primitive_imag.get());
    af_retain_array(&af_p_absolute, primitive_absolute.get());
    af_retain_array(&af_p_angle, primitive_angle.get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p_real;
    tmp[2] = (jlong)af_p_imag;
    tmp[3] = (jlong)af_p_absolute;
    tmp[4] = (jlong)af_p_angle;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);
    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_firstLocationOfMaximum(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::firstLocationOfMaximum(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_firstLocationOfMinimum(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::firstLocationOfMinimum(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_friedrichCoefficients(JNIEnv *env, jobject thisObj, jlong ref, jint m,
                                                                     jfloat r) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::friedrichCoefficients(var, m, r).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_hasDuplicates(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::hasDuplicates(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_hasDuplicateMax(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::hasDuplicateMax(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_hasDuplicateMin(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::hasDuplicateMin(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_indexMassQuantile(JNIEnv *env, jobject thisObj, jlong ref, jfloat q) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::indexMassQuantile(var, q).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_kurtosis(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::kurtosis(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_largeStandardDeviation(JNIEnv *env, jobject thisObj, jlong ref,
                                                                      jfloat r) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::largeStandardDeviation(var, r).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_lastLocationOfMaximum(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::lastLocationOfMaximum(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_lastLocationOfMinimum(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::lastLocationOfMinimum(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_length(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::length(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_linearTrend(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 6;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer_pvalue = 0;
    af_array af_p_pvalue = (af_array)raw_pointer_pvalue;

    jlong raw_pointer_rvalue = 0;
    af_array af_p_rvalue = (af_array)raw_pointer_rvalue;

    jlong raw_pointer_intercept = 0;
    af_array af_p_intercept = (af_array)raw_pointer_intercept;

    jlong raw_pointer_slope = 0;
    af_array af_p_slope = (af_array)raw_pointer_slope;

    jlong raw_pointer_stderr = 0;
    af_array af_p_stderr = (af_array)raw_pointer_stderr;

    af_retain_array(&arr, var.get());

    af::array primitive_pvalue;
    af::array primitive_rvalue;
    af::array primitive_intercept;
    af::array primitive_slope;
    af::array primitive_stderr;

    tsa::features::linearTrend(var, primitive_pvalue, primitive_rvalue, primitive_intercept, primitive_slope,
                               primitive_stderr);

    af_retain_array(&af_p_pvalue, primitive_pvalue.get());
    af_retain_array(&af_p_rvalue, primitive_rvalue.get());
    af_retain_array(&af_p_intercept, primitive_intercept.get());
    af_retain_array(&af_p_slope, primitive_slope.get());
    af_retain_array(&af_p_stderr, primitive_stderr.get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p_pvalue;
    tmp[2] = (jlong)af_p_rvalue;
    tmp[3] = (jlong)af_p_intercept;
    tmp[4] = (jlong)af_p_slope;
    tmp[5] = (jlong)af_p_stderr;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);
    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_localMaximals(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::localMaximals(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_longestStrikeAboveMean(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::longestStrikeAboveMean(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_longestStrikeBelowMean(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::longestStrikeBelowMean(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_maxLangevinFixedPoint(JNIEnv *env, jobject thisObj, jlong ref, jint m,
                                                                     jfloat r) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::maxLangevinFixedPoint(var, m, r).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_maximum(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::maximum(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_mean(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::mean(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_meanAbsoluteChange(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::meanAbsoluteChange(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_meanChange(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::meanChange(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_meanSecondDerivativeCentral(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::meanSecondDerivativeCentral(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_median(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::median(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_minimum(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::minimum(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_numberCrossingM(JNIEnv *env, jobject thisObj, jlong ref, jint m) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::numberCrossingM(var, m).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_numberCwtPeaks(JNIEnv *env, jobject thisObj, jlong ref, jint maxW) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::numberCwtPeaks(var, maxW).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_numberPeaks(JNIEnv *env, jobject thisObj, jlong ref, jint n) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::numberPeaks(var, n).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_partialAutocorrelation(JNIEnv *env, jobject thisObj, jlong ref,
                                                                      jlong lags) {
    jint l = 3;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);
    af_array arr_lags = (af_array)lags;
    af::array var_lags = af::array(arr_lags);
    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&arr_lags, var_lags.get());

    af_retain_array(&af_p, tsa::features::partialAutocorrelation(var, var_lags).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)arr_lags;
    tmp[2] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_percentageOfReoccurringDatapointsToAllDatapoints(JNIEnv *env,
                                                                                                jobject thisObj,
                                                                                                jlong ref,
                                                                                                jboolean isSorted) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::percentageOfReoccurringDatapointsToAllDatapoints(var, isSorted).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_percentageOfReoccurringValuesToAllValues(JNIEnv *env, jobject thisObj,
                                                                                        jlong ref, jboolean isSorted) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::percentageOfReoccurringValuesToAllValues(var, isSorted).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_quantile(JNIEnv *env, jobject thisObj, jlong ref, jlong q,
                                                        jfloat precision) {
    jint l = 3;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);
    af_array arr_q = (af_array)q;
    af::array var_q = af::array(arr_q);
    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&arr_q, var_q.get());

    af_retain_array(&af_p, tsa::features::quantile(var, var_q, precision).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)arr_q;
    tmp[2] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_rangeCount(JNIEnv *env, jobject thisObj, jlong ref, jfloat min,
                                                          jfloat max) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::rangeCount(var, min, max).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_ratioBeyondRSigma(JNIEnv *env, jobject thisObj, jlong ref, jfloat r) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::ratioBeyondRSigma(var, r).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_ratioValueNumberToTimeSeriesLength(JNIEnv *env, jobject thisObj,
                                                                                  jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::ratioValueNumberToTimeSeriesLength(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_sampleEntropy(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::sampleEntropy(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_skewness(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::skewness(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_spktWelchDensity(JNIEnv *env, jobject thisObj, jlong ref, jint coeff) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::spktWelchDensity(var, coeff).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_standardDeviation(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::standardDeviation(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_sumOfReoccurringDatapoints(JNIEnv *env, jobject thisObj, jlong ref,
                                                                          jboolean isSorted) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::sumOfReoccurringDatapoints(var, isSorted).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_sumOfReoccurringValues(JNIEnv *env, jobject thisObj, jlong ref,
                                                                      jboolean isSorted) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::sumOfReoccurringValues(var, isSorted).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_sumValues(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::sumValues(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_symmetryLooking(JNIEnv *env, jobject thisObj, jlong ref, jfloat r) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::symmetryLooking(var, r).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_timeReversalAsymmetryStatistic(JNIEnv *env, jobject thisObj, jlong ref,
                                                                              jint lag) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::timeReversalAsymmetryStatistic(var, lag).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_valueCount(JNIEnv *env, jobject thisObj, jlong ref, jfloat v) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::valueCount(var, v).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_variance(JNIEnv *env, jobject thisObj, jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::variance(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

JNIEXPORT jlongArray JNICALL Java_tsa_Features_varianceLargerThanStandardDeviation(JNIEnv *env, jobject thisObj,
                                                                                   jlong ref) {
    jint l = 2;
    jlong tmp[l];
    jlongArray pointers = env->NewLongArray(l);

    af_array arr = (af_array)ref;
    af::array var = af::array(arr);

    jlong raw_pointer = 0;
    af_array af_p = (af_array)raw_pointer;

    af_retain_array(&arr, var.get());
    af_retain_array(&af_p, tsa::features::varianceLargerThanStandardDeviation(var).get());

    tmp[0] = (jlong)arr;
    tmp[1] = (jlong)af_p;

    env->SetLongArrayRegion(pointers, 0, l, &tmp[0]);

    return pointers;
}

#ifdef __cplusplus
}
#endif
