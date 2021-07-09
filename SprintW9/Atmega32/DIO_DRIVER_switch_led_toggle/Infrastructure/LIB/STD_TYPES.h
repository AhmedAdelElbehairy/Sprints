#ifndef REPO_LIB_STD_TYPES_H_
#define REPO_LIB_STD_TYPES_H_
	
	typedef unsigned char uint8_t;
	typedef unsigned short int uint16_t;
	typedef unsigned long int uint32_t;

	typedef signed char int8_t;
	typedef signed short int int16_t;
	typedef signed long int int32_t;

	typedef float float32_t;
	typedef double float64_t;

	typedef long double float96_t;
	
	typedef uint8_t Byte;
	
	typedef union
	{
		uint8_t byte;
		struct
		{
			uint8_t bit1 :1;
			uint8_t bit2 :1;
			uint8_t bit3 :1;
			uint8_t bit4 :1;
			uint8_t bit5 :1;
			uint8_t bit6 :1;
			uint8_t bit7 :1;
			uint8_t bit8 :1;
		}bits;
	}uniregister;

#endif /* REPO_LIB_STD_TYPES_H_ */