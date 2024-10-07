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


    template<typename T1>
    class Signal<T1> {
    public:
        auto connect(const std::function<void(T1)>& callback) {
            callbacks.pushBack(callback);
        }
        auto connect(const std::function<void()>& callback) {
            callbacks.pushBack([&callback](T1 arg1) { callback(); });
        }

        auto emit(const T1& arg1) {
            for (const auto& callback : callbacks) {
                callback(arg1);
            }
        }
        
    protected:
        Array<std::function<void(T1)>> callbacks;
    };


    template<typename T1, typename T2>
    class Signal<T1, T2> {
    public:
        auto connect(const std::function<void(T1, T2)>& callback) {
            callbacks.pushBack(callback);
        }
        auto connect(const std::function<void(T1)>& callback) {
            callbacks.pushBack([&callback](T1 arg1, T2 arg2) { callback(arg1); });
        }
        auto connect(const std::function<void()>& callback) {
            callbacks.pushBack([&callback](T1 arg1) { callback(); });
        }

        auto emit(const T1& arg1, const T2& arg2) {
            for (const auto& callback : callbacks) {
                callback(arg1, arg2);
            }
        }
        
    protected:
        Array<std::function<void(T1, T2)>> callbacks;
    };


    template<typename T1, typename T2, typename T3>
    class Signal<T1, T2, T3> {
    public:
        auto connect(const std::function<void(T1, T2, T3)>& callback) {
            callbacks.pushBack(callback);
        }
        auto connect(const std::function<void(T1, T2)>& callback) {
            callbacks.pushBack([&callback](T1 arg1, T2 arg2, T3 arg3) { callback(arg1, arg2); });
        }
        auto connect(const std::function<void(T1)>& callback) {
            callbacks.pushBack([&callback](T1 arg1, T2 arg2, T3 arg3) { callback(arg1); });
        }
        auto connect(const std::function<void()>& callback) {
            callbacks.pushBack([&callback](T1 arg1, T2 arg2, T3 arg3) { callback(); });
        }

        auto emit(const T1& arg1, const T2& arg2, const T3& arg3) {
            for (const auto& callback : callbacks) {
                callback(arg1, arg2, arg3);
            }
        }
        
    protected:
        Array<std::function<void(T1, T2, T3)>> callbacks;
    };

}
