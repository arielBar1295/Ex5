////
//// Created by ariel on 06/05/2019.
////
//
#ifndef UNTITLED_RANGE_HPP
#define UNTITLED_RANGE_HPP

#endif //UNTITLED_RANGE_HPP

#include <iostream>
//#include "range.hpp"
#include <bits/stdc++.h>
namespace itertools {

    using namespace std;

    // template<class T>
    template<typename T, typename U>
    class chainIt {
        T a;
        U b;
    public:
        chainIt( T& a1,  U& b1) {
            a = a1;
            b = b1;
        }
        chainIt(){

        }

        class iterator {
            decltype(a.begin()) tStart;
            decltype(a.end()) tEnd;
            decltype(b.begin()) uStart;
            decltype(b.end()) uEnd;

        public:
            iterator(T& a, U& b) {
                tStart = a.begin();
                tEnd = a.end();
                uStart = b.begin();
                uEnd = b.end();
            }
            iterator(T &a, U &b,bool f) {
                tStart = a.end();
                tEnd = a.end();
                uStart = b.end();
                uEnd = b.end();
            }
            iterator(){

            }

            auto operator*() const {
             if(tStart!=tEnd)
                return *tStart;
             else
                return *uStart;
            }

            iterator& operator++() {
                if (tEnd != tStart)
                    ++tStart;
                else
                    ++uStart;
                return *this;
            }

            bool operator!=(const iterator &other)  {
                if (tStart != other.tStart) {
                    return true;
                }
                if (uStart != other.uStart) {
                    return true;
                }
                return false;
            }

//            }
        };

        iterator begin() {
            return iterator(a, b);
        }

        iterator end() {
            return iterator(a, b, false);
        }
    };

    template<typename T, typename U>chainIt<T,U> chain(T a, U b) {
        return chainIt<T,U>(a, b);

    }
}