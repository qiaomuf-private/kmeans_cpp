/***************************************************************************
 *
 * Copyright (c) 2024 bytedance.com, Inc. All Rights Reserved
 *
 **************************************************************************/



/**
 * @file kmeans.h
 * @author qiaomu(com@bytedance.com)
 * @date 2024/01/06 11 ±56∑÷49√Î
 * @brief
 *
 **/

#ifndef KMEANS_H_
#define KMEANS_H_
#include "sample.h"

namespace kmeans {

class Kmeans {
public:
    Kmeans(std::shared_ptr<std::vector<Sample>> samples, int k) : k_(k), samples_(samples) {
    }
    void run(int epoch);
    void save(const std::string& filename) const;

private:
    void pick_center();
    void point_clustering();
    void mean_center();
    int k_;
    std::shared_ptr<std::vector<Sample>> centers_;
    std::shared_ptr<std::vector<Sample>> samples_;
};

}

#endif  // KMEANS_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

