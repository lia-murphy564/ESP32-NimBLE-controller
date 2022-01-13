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
    unsigned int val: 12;
    unsigned int idx: 3;
    unsigned int type: 1;
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
    Parameter();
    //~ParameterSS();

    void configure(parameter_config* conf) {
        //&config = conf;
        param.val = conf->val;
        param.type = conf->type;
        param.idx = conf->idx;

    }

    void setValue(int v) {
        param.val = v;
    }

    int getValue() {
        return param.val;
    }
};


#endif // __PARAMETER_H__