#pragma once
#include <exception>
#include <stdexcept> // std::runtime_error
#include "cilia/BasicTypes.hpp"

namespace cilia {

    /// Catch "const ExceptionBase&"
    using ExceptionBase = std::exception;
    /// Throw "ExceptionBase("message")"
    using Exception = std::runtime_error;

    class Exception2;

    //TODO This does not really work, as
    //       catch (const Exception1& ex)
    //     does not catch exception.
    //class Exception1 : public std::exception {
    class Exception1 : public std::runtime_error {
    public:
        //using std::exception::exception;
        using std::runtime_error::runtime_error;

        Exception1(StringView str) : std::runtime_error(String(str)) { }
        Exception1(const std::runtime_error& re) : std::runtime_error(re) { }
        
        //TODO Does not help
        operator Exception2&() {
            return *reinterpret_cast<Exception2*>(this);
        }
        operator const Exception2&() const {
            return *reinterpret_cast<const Exception2*>(this);
        }

        auto message() const noexcept -> StringView {
            return std::exception::what();
        }
    };

    //TODO This does not really work, as
    //       catch (const Exception2& ex)
    //     does not catch Exception1 either.
    class Exception2 : public Exception1 {
	public:
        using Exception1::Exception1;

        //Exception2(StringView str) : std::runtime_error(str) { }
        //Exception2(const std::runtime_error& re) : std::runtime_error(re) { }
	};

    class Exception3 : public Exception2 {
    public:
        using Exception2::Exception2;
    };

}
