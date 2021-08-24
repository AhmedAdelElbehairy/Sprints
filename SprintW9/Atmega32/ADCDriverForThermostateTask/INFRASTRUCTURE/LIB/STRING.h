/*
 * STRING.h
 *
 *  Created on: Aug 6, 2021
 *      Author: zoldeyck
 */

#ifndef INFRASTRUCTURE_LIB_STRING_H_
#define INFRASTRUCTURE_LIB_STRING_H_

uint8_t STR_Length(uint8_t* String, uint16_t* StringLength);
uint8_t STR_CharIsNumeric(uint8_t Character, uint8_t* Result);
uint8_t STR_StringIsNumeric(uint8_t* String, uint8_t* Result);
uint8_t STR_CompareString(uint8_t* String_1, uint8_t* String_2, uint8_t* Result);
uint8_t STR_String2Number(uint8_t* String, uint16_t* Number);
uint8_t STR_Number2String(uint32_t Number, uint8_t* String);
uint8_t STR_StringReverse(uint8_t* String);




#endif /* INFRASTRUCTURE_LIB_STRING_H_ */
