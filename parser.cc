#include "parser.h"
#include <fstream>
#include <string>
#include <sstream>

namespace kmeans {

std::shared_ptr<std::vector<Sample>> Parser::get_training_data(const std::string& filename) {
    std::shared_ptr<std::vector<Sample>> data(new std::vector<Sample>);
    std::ifstream input(filename);
    std::string line;
    std::string token;
    float value;
    while(std::getline(input, line)) {
        Sample sample;
        std::stringstream ss(line);
        ss >> token;
        sample.set_token(token);
        for (int i = 0; i != DIM; ++i) {
            ss >> value;
            sample.set_value(value, i);
        }
        data->push_back(sample);
    }
    return data;
}

}
