#ifndef _MAIN_HPP_
#define _MAIN_HPP_

#include <iostream>
#include <cstddef>
#include <cstdio>
#include <string>
#include <vector>

#include "netImpl.hpp"

using namespace std;

//const string DATA_ROOT = string(PROJECT_SRC_DIR) + string("/data");
const char * DATA_ROOT = "../../data";
const int64_t TRAIN_BATCH_SIZE = 64;
const int64_t TEST_BATCH_SIZE = 1000;
const int64_t NUMBER_OF_EPOCHS = 10;
const int64_t LOG_INTERVAL = 10;

#endif //_MAIN_HPP_
