/***************************************************************************
 *
 * Copyright (c) 2024 bytedance.com, Inc. All Rights Reserved
 *
 **************************************************************************/



/**
 * @file sample.h
 * @author qiaomu(com@bytedance.com)
 * @date 2024/01/06 11 ±23∑÷36√Î
 * @brief
 *
 **/

#ifndef SAMPLE_H_
#define SAMPLE_H_
#include <string>
#include <vector>
#include <fstream>

namespace kmeans {

constexpr static int DIM = 50;

class Sample {
public:
    Sample(): center_num_(0) {
        data_.resize(DIM);
    }
    void set_token(const std::string& t) {
        token_ = t;
    }

    void set_value(float v, int dim) {
        data_[dim] = v;
    }

    void set_center_id(size_t id) {
        center_id_ = id;
    }

    float distance(const Sample& sample) const;

    void add_to_center(Sample* sample) const;

    void mean();

    size_t id() const {
        return center_id_;
    }

    void print();

    void save(std::ofstream* output) const;
private:
    std::string token_;
    std::vector<float> data_;
    size_t center_id_;
    size_t center_num_;
};

}

#endif  // SAMPLE_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

