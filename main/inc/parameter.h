/*
 * File: parameter.h
 * File Created: Wednesday, 12th January 2022 6:57 pm
 * Author: Lia Murphy (wxm219@miami.edu)
 */

#ifndef __PARAMETER_H__
#define __PARAMETER_H__

#pragma once

enum param_type {
    pot = 0x00,
    sw = 0x01 
}; 

enum param_index {
    pot0 = 0x00,
    pot1 = 0x01,
    pot2 = 0x02,
    pot3 = 0x03,
    pot4 = 0x04,
    sw1 = 0x05,
    sw2 = 0x06,
    fsw = 0x07
};

struct parameter_bit_field {
    unsigned int val: 12; // 0 to 4096
    unsigned int idx: 3; // 0 to 7
    unsigned int type: 1; // 0 to 1
    // bit[11] val;
    // bit[2] idx;
    // bit type;
};

struct parameter_config {
    unsigned int val;
    param_type type;
    param_index idx;
};

class Parameter {
private:
    parameter_bit_field param;
    parameter_config config;
public:
    Parameter() {}
    ~Parameter() {}

    void configure(parameter_config* conf) {
        //&config = conf;
        param.val = conf->val;
        param.type = conf->type;
        param.idx = conf->idx;
    }

    void setValue(unsigned int v) {
        param.val = v;
    }

    unsigned int getValue() {
        return param.val;
    }

    unsigned int getBitField() {
        unsigned int ret = param.type << 15 | param.idx << 12 | param.val;
        return ret;
    }
};


#endif // __PARAMETER_H__