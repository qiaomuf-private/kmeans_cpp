#include "parser.h"
#include "kmeans.h"
#include <sstream>

int main(int argc, char** argv) {
    if (argc != 5) {
        std::cerr << "Input: ./kmeans input_file output_center_file k epoch" << std::endl;
        return 1;
    }
    int k;
    int epoch;
    std::string k_str = std::string(argv[3]) + " " + std::string(argv[4]);
    std::stringstream k_ss(k_str);
    k_ss >> k;
    k_ss >> epoch;
    std::cout << "k=" << k << " epoch=" << epoch << std::endl;
    kmeans::Parser parser;
    kmeans::Kmeans kmeans(parser.get_training_data(argv[1]), k);
    kmeans.run(epoch);
    kmeans.save(argv[2]);
}
