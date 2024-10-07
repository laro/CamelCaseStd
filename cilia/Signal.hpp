#pragma once
#include "cilia/BasicTypes.hpp"
#include "cilia/Array.hpp"
#include <functional>
#include <algorithm>

namespace cilia {

    /// Informs registered/connected callbacks ("slots") about an event.
    template<typename... TArgs>
    class Signal {
    public:
        auto connect(const std::function<void(TArgs...)>& callback) {
            callbacks.append(callback);
        }

        //TODO It is diffficult to implement a disconnect(), as there is no operator==
        //     on std::function.
        //auto disconnect(const std::function<void(TArgs...)>& callbackToDisconnect) {
        //    //TODO Member function find(), contains()
        //    //auto iter = std::find(callbacks.begin(), callbacks.end(), callback);
        //    for (auto iter = callbacks.cbegin(); iter != callbacks.cend(); ++iter) {
        //        //auto target = iter->target<void(TArgs...)>();
        //        //if ((*iter).target<void(*)(TArgs...)>() == callbackToDisconnect.target())
        //        //    callbacks.erase(iter);
        //    }
        //}

        auto emit(TArgs... args) {
            for (const auto& callback : callbacks) {
                callback(args...);
            }
        }
        
    protected:
        Array<std::function<void(TArgs...)>> callbacks;
    };

}
