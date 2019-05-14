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
       const T a;
         const T b;
         //constructor
        itrange(const T& a1,const T& b1):a(a1),b(b1){}



        class iterator {
        private:
            T m_pointer;
        public:
            iterator(){
                m_pointer=NULL;
            }
            iterator(const T pointer) {
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

        iterator begin() const{
            return iterator{a};
        }

        iterator end()const {
            return iterator{b};
        }
        //return the size of the range.
        int size ()const{
            T start=a;
            T end=b;
            int s=0;
            while(start!=end) {
                start++;
                s++;
            }
            return s;
        }

    };

//return the class
    template<typename T> itrange <T> range(T a, T b) {
        return itrange<T>(a, b);


    }

}
