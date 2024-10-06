#pragma once
#include "cilia/BasicTypes.hpp"
#include "cilia/Array.hpp"

namespace cilia {

    /// Informs registered/connected callbacks ("slots") about an event.
    template<TArgs ...>
    class Signal {
    public:
        auto connect(const std::function& callback) {
            callbacks.append(callback);
        }

        auto disconnect(const std::function& callback) {
            callbacks.remove(callback);
        }

        auto emit<TArgs ...>();
        
    protected:
        Array<std::function> callbacks;
    };

}
