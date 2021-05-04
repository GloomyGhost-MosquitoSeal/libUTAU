//
// Created by YuzukiTsuru on 2021/3/13.
//

#include "ScaleConvert.h"

#include <utility>

ScaleConvert::ScaleConvert(std::string scaleName) {
    ScaleConvertToDouble(std::move(scaleName));
}

bool ScaleConvert::ScaleConvertToDouble(std::string scaleName) {
    int bias = 0;

    if (scaleName[1] == '#') {
        bias = 1;
    }

    int scale = 0;
    switch (scaleName[0]) {
        case 'C':
            scale = -9 + bias;
            break;
        case 'D':
            scale = -7 + bias;
            break;
        case 'E':
            scale = -5;
            break;
        case 'F':
            scale = -4 + bias;
            break;
        case 'G':
            scale = -2 + bias;
            break;
        case 'A':
            scale = bias;
            break;
        case 'B':
            scale = 2;
            break;
        default:
            return false;
    }

    double octave = scaleName[1 + bias] - '0' - 4;
    scaleNum = pow(2.0, octave) * pow(2.0, static_cast<double>(scale) / 12.0) * 440.00;

    return true;
}

double ScaleConvert::GetScaleNum() const {
    return scaleNum;
}

