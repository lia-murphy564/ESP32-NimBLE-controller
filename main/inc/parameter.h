/*
 * File: parameter.h
 * File Created: Wednesday, 12th January 2022 6:57 pm
 * Author: Lia Murphy (wxm219@miami.edu)
 */

#ifndef __PARAMETER_H__
#define __PARAMETER_H__

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
    unsigned int nil: 13;
};

struct parameter_config {
    param_type type;
    param_index idx;
};

class Parameter {
private:
    parameter_bit_field* param;
    parameter_config* config;
public:
    Parameter();
    ~Parameter();

    void configure(parameter_config* conf);

    parameter_config getConfig();

    void setValue(unsigned int v);
    unsigned int getValue();

    void setType(param_type type);
    param_type getType();

    void setIndex(param_index idx);
    param_index getIndex();

    unsigned int getBitField();
};


#endif // __PARAMETER_H__