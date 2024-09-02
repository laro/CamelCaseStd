#pragma once
#include <cstdint>
#include <cstddef>  // nullptr_t
//#include <stdfloat> // std::float16_t, std::bfloat16_t
#include <limits>

namespace cilia {

	//TODO #if 64 bit
	using Int  = int64_t;
	using UInt = uint64_t;
	//TODO #else
	//using Int = int32_t;
	//using UInt = uint32_t;
	//TODO #endif

	using Int8  = int8_t;
	using Int16 = int16_t;
	using Int32 = int32_t;
	using Int64 = int64_t;

	using UInt8  = uint8_t;
	using UInt16 = uint16_t;
	using UInt32 = uint32_t;
	using UInt64 = uint64_t;

	using Bool = bool;
	using Byte = uint8_t;
	using Char = unsigned char;

	using Float    = float;
	//using Float16 = std::float16_t; // _Float16;
	using Float32  = float;
	using Float64  = double;
	//using BFloat16 = std::bfloat16_t; // __bf16;


	const static Bool True  = true;
	const static Bool False = false;

	const static nullptr_t NullPtr = nullptr;

	const static Float32 NaN      = std::numeric_limits<Float32>::quiet_NaN();
	const static Float32 Infinity = std::numeric_limits<Float32>::infinity();

}
