//
// Created by ariel on 08/05/2019.
//

#ifndef UNTITLED_ZIP_HPP
#define UNTITLED_ZIP_HPP

#endif //UNTITLED_ZIP_HPP

#include <utility>
#include <iostream>
//#include "range.hpp"
#include <bits/stdc++.h>
using namespace std;
namespace itertools {

    using namespace std;

    // template<class T>
    template<typename T, typename U>

    class zip {
        const T a;
        const  U b;


    public:
        zip(){

        }
        zip(const T& a1,const U& b1):a(a1),b(b1){}


        class iterator {
            //return the size of the chain.
            decltype(a.begin()) tStart;
            decltype(a.end()) tEnd;
            decltype(b.begin()) uStart;
            decltype(b.end()) uEnd;


        public:
            iterator(){

            }
            iterator(const T& a,const  U& b) {
                tStart = a.begin();
                tEnd = a.end();
                uStart = b.begin();
                uEnd = b.end();
            }
            //constructor for the end
            iterator(const T &a, const U &b,bool f) {
                tStart = a.end();
                tEnd = a.end();
                uStart = b.end();
                uEnd = b.end();
            }

            auto operator*()  {
                return make_pair(*tStart,*uStart);
            }

            iterator& operator++() {
                if (tEnd != tStart) {
                    ++tStart;
                    ++uStart;
                }
                return *this;
            }

            bool operator!=(const iterator &other) {
                if (tStart != other.tStart && uStart != other.uStart)
                    return true;
                else return false;
            }

        };

        iterator begin() const {
            return iterator(a, b);
        }

        iterator end() const{
            return iterator(a, b, false);
        }
        int size () const{
            decltype(a.begin()) start1=a.begin();
            decltype(a.end()) end1=a.end();
            int s=0;
            while(start1!=end1) {
                ++start1;
                s++;
            }

            return (s);
        }

    };


//operator ostream for the pair.
    template<typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& v){

        os << v.first << ","
           << v.second;
        return os;
    }

}
