#ifndef _MAIN_HPP_
#define _MAIN_HPP_

#include <iostream>
#include <cstddef>
#include <cstdio>
#include <string>
#include <vector>

#include "netImpl.hpp"

using namespace std;

torch::Device device(torch::cuda::is_available() ? torch::kCUDA : torch::hasMPS() ? torch::kMPS : torch::kCPU);

const char * DATA_ROOT = "../data";
const int64_t TRAIN_BATCH_SIZE = 64;
const int64_t TEST_BATCH_SIZE = 1000;
const int64_t NUMBER_OF_EPOCHS = 10;
const int64_t LOG_INTERVAL = 10;

#endif //_MAIN_HPP_
