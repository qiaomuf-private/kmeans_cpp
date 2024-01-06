#include "sample.h"
#include <iostream>
#include <cmath>

namespace kmeans {

void Sample::print() {
    std::cout << token_;
    for(auto v : data_) {
        std::cout << ' ' << v;
    }
    std::cout << std::endl;
}

float Sample::distance(const Sample& sample) const {
    float sum = 0.0;
    for (size_t i = 0; i != data_.size(); ++i) {
        sum += std::pow(data_[i] - sample.data_[i], 2);
    }
    return sum;
}

void Sample::add_to_center(Sample* center) const {
    for (int i = 0; i != data_.size(); ++i) {
        center->data_[i] += data_[i];
    }
    ++center->center_num_;
}

void Sample::mean() {
    for (int i = 0; i != data_.size(); ++i) {
        data_[i] /= center_num_;
    }
}

void Sample::save(std::ofstream* output) const {
    for (int i = 0; i != data_.size(); ++i) {
        *output << data_[i] << ' ';
    }
    *output << center_id_ << std::endl;
}

}
