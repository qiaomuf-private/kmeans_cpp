/***************************************************************************
 *
 * Copyright (c) 2024 bytedance.com, Inc. All Rights Reserved
 *
 **************************************************************************/



/**
 * @file parser.h
 * @author qiaomu(com@bytedance.com)
 * @date 2024/01/06 11 ±18∑÷51√Î
 * @brief
 *
 **/

#ifndef PARSER_H_
#define PARSER_H_
#include "sample.h"
#include <vector>
#include <memory>
#include <iostream>

namespace kmeans {

class Parser {
public:
    std::shared_ptr<std::vector<Sample>> get_training_data(const std::string& filename);
};

}

#endif  // PARSER_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

