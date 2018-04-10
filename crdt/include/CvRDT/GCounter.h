#pragma once

#include <unordered_map>
#include <algorithm> // std::max
#include <iostream>
#include <cassert>

namespace CRDT {
namespace CvRDT {


/**
 * Grow Only Counter.
 * CvRDT (State-based)
 *
 * \note
 * Internally stores counter in a map. Key is the replicate's unique id.
 *
 *
 * \tparam T Type of counter. (Default int)
 * \tparam ID Type of the id used to identify each replicated. (Each unique).
 *
 * \author  Constantin Masson
 * \date    March 2018
 */
template<typename T = int, typename ID = std::string>
class GCounter {
    private:
        std::unordered_map<ID, T> _map;
        const ID _currentID;


    public:
        GCounter(const ID id) : _currentID(id) {}


    // -------------------------------------------------------------------------
    // Methods
    // -------------------------------------------------------------------------

    public:

        /**
         * Get a copy of the current counter value.
         */
        T query() const {
            T value = 0;
            for(const auto& it : _map) {
                value += it.second;
            }
            return value;
        }

        /**
         * Increment the counter by one.
         * Internally increment the counter at current process id.
         */
        void increment() {
            _map[_currentID] += 1;
        }

        /**
         * Increment the counter by specific amount.
         *
         * \warning
         * Negative number are reset to 0.
         */
        void increment(const T& value) {
            assert(value >= 0);
            _map[_currentID] += std::max(value, 0); // negativ numb -> 0
        }

        /**
         * Merge this Counter with another.
         * Current counter is modified.
         */
        void merge(const GCounter<T,ID>& other) {
            for(const auto& it : other._map) {
                _map[it.first] = std::max(_map[it.first], it.second);
            }
        }


    // -------------------------------------------------------------------------
    // Operators overload
    // -------------------------------------------------------------------------

    public:

        friend bool operator==(const GCounter& lhs, const GCounter& rhs) {
            return lhs.query() == rhs.query();
        }

        friend bool operator!=(const GCounter& lhs, const GCounter& rhs) {
            return !(lhs == rhs);
        }

        friend std::ostream& operator<<(std::ostream& out, const GCounter& o) {
            out << "GCounter = " << o.query() << " -> [";
            for(const auto& it: o._map) {
                out << it.first << ":" << it.second << " ";
            }
            out << "]";
            return out;
        }
};


}} // End namespaces
