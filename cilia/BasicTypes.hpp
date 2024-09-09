#pragma once
#include <cstdint>
#include <cstddef>  // nullptr_t
//#include <stdfloat> // std::float16_t, std::bfloat16_t, but C++23
#include <limits>

namespace cilia {

#if defined(_WIN64) || defined(__x86_64__) || defined(__aarch64__) // MSVC and GCC defines to signal 64 bit systems
	using Int  = int64_t;
	using UInt = uint64_t;
#else
	using Int  = int32_t;
	using UInt = uint32_t;
#endif

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

	using NullPtrType = nullptr_t;
	const static NullPtrType NullPtr = nullptr;

	const static Float32 NaN      = std::numeric_limits<Float32>::quiet_NaN();
	const static Float32 Infinity = std::numeric_limits<Float32>::infinity();

}
