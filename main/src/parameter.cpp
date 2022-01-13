/*
 * File: parameter.cpp
 * File Created: Wednesday, 12th January 2022 11:54 pm
 * Author: Lia Murphy (wxm219@miami.edu)
 */

#include "parameter.h"

Parameter::Parameter() {
    param = new parameter_bit_field();
    param->val = 0x00;
    param->type = pot;
    param->idx = pot0;
    param->nil = 0x00;
}

Parameter::~Parameter() {
    delete param;
    param = NULL;
}

Parameter::configure(parameter_config* conf) {
    config = conf;
    param->type = conf->type;
    param->idx = conf->idx;
}

Parameter::getConfig() {
    return this->config;
}

Parameter::setValue(unsigned int v) {
    param->val = v;
}

Parameter::getValue() {
    return param->val;
}

Parameter::setType(param_type type) {
    param->type = type;
}

Parameter::getType() {
    retrun param->type;
}

Parameter::setIndex(param_index idx) {
    param->idx = idx;
}

Parameter::getIndex() {
    return param->idx;
}

Parameter::getBitField() {
    unsigned int ret = param->type << 15 | param->idx << 12 | param->val;
    return ret;
}