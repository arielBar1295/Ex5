//
// Created by ariel on 06/05/2019.
//

#ifndef UNTITLED_RANGE_HPP
#define UNTITLED_RANGE_HPP

#endif //UNTITLED_RANGE_HPP
#include <bits/stdc++.h>
#include <iostream>
#pragma once
namespace itertools {

    using namespace std;

    // template<class T>
    template<typename T>
    class itrange {
    public:
         itrange(){

        }
        T a, b;

        itrange(T& a1, T& b1) {
          //  const bool bb=std::is_same<decltype(a1),decltype(b1)>::value;
            a = a1;
            b = b1;
        }


        class iterator {
        private:
            T m_pointer;
        public:
            iterator(){
                m_pointer=NULL;
            }
            iterator(T pointer) {
                m_pointer = pointer;
            }

            T operator*() const {
                return m_pointer;
            }

            bool operator==(const T &other) const {
                return m_pointer == other;
            }

            const iterator operator++(int) {
                iterator tmp = *this;
                m_pointer = m_pointer++;
                return tmp;
            }

            iterator &operator++() {
                m_pointer++;
                return *this;
            }

            bool operator!=(const iterator &other) const {
                return m_pointer != other.m_pointer;
            }


        };

        iterator begin() {
            return iterator{a};
        }

        iterator end() {
            return iterator{b};
        }

    };


    template<typename T> itrange <T> range(T a, T b) {
        return itrange<T>(a, b);

    }
}