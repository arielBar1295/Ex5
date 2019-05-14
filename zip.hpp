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

    class zipIt {
        const T a;
        const  U b;


    public:
        zipIt(){

        }
        zipIt(const T& a1,const U& b1):a(a1),b(b1){}


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

            auto operator*() const {
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

    };

//function returns the class
template<typename T, typename U>zipIt<T,U> zip(T a, U b) {
    return zipIt<T, U>(a, b);
}
//operator ostream for the pair.
    template<typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& v){

        os << v.first << ","
           << v.second<<" ";
        return os;
    }

}
