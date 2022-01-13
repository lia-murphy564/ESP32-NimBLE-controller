/*
 * File: parameter.cpp
 * File Created: Wednesday, 12th January 2022 10:31 pm
 * Author: Lia Murphy (wxm219@miami.edu)
 */

#include "parameter.h"

Parameter::configure(parameter_config* conf) {
    //&config = conf;
    param.val = conf->val;
    param.idx = conf->idx;
    param.type = conf->type;
}

Parameter::setValue(int v) {
    param.val = v;
}