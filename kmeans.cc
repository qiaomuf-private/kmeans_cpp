#include "kmeans.h"
#include <iostream>
#include <limits>

namespace kmeans {

void Kmeans::pick_center() {
    centers_.reset(new std::vector<Sample>);
    centers_->resize(k_);
    for (int i = 0; i != k_; ++i) {
        size_t index = rand() % samples_->size();
        (*centers_)[i] = (*samples_)[index];
    }
}

void Kmeans::point_clustering() {
    for (auto& sample : *samples_) {
        float min_dis = std::numeric_limits<float>::max();
        for (size_t i = 0; i != centers_->size(); ++i) {
            auto& center = (*centers_)[i];
            float dis = sample.distance(center);
            if (dis < min_dis) {
                min_dis = dis;
                sample.set_center_id(i);
            }
        }
    }
}

void Kmeans::mean_center() {
    centers_.reset(new std::vector<Sample>);
    centers_->resize(k_);
    for (auto& sample : *samples_) {
        sample.add_to_center(&(*centers_)[sample.id()]);
    }
    for (auto& center : *centers_) {
        center.mean();
    }
}

void Kmeans::run(int epoch) {
    pick_center();
    for (int i = 0; i != epoch; ++i) {
        point_clustering();
        mean_center();
        std::cout << "epoch " << i << " finished" << std::endl;
    }
}

void Kmeans::save(const std::string& filename) const {
    std::ofstream output(filename);
    for (auto& center : *centers_) {
        center.save(&output);
    }
    std::ofstream output_data(filename + ".data");
    for (auto& sample : *samples_) {
        sample.save(&output_data);
    }
}

}
