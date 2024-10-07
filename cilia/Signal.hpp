#pragma once
#include "cilia/BasicTypes.hpp"
#include "cilia/Array.hpp"
#include <functional>

namespace cilia {

    /// Informs registered/connected callbacks ("slots") about an event.
    template<typename... TArgs>
    class Signal {
    public:
        auto connect(const std::function<void(TArgs...)>& callback) {
            callbacks.append(callback);
        }

        auto disconnect(const std::function<void(TArgs...)>& callback) {
            callbacks.remove(callback);
        }

        auto emit(TArgs... args) {
            for (const auto& callback : callbacks) {
                callback(args...);
            }
        }
        
    protected:
        Array<std::function<void(TArgs...)>> callbacks;
    };

}
