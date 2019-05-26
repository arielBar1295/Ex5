#include <iostream>
#include <utility>
#include <bits/stdc++.h>
#include<math.h>
//using namespace std;
namespace itertools {
//main idea:


    template<typename T>
    class powerset {
        const T a;
    public:
        powerset(const T& a1) : a(a1)
        {}

        powerset(){

        }

        class iterator {
            std::pair <unsigned int, T> pair1;


        public:
            iterator(const std::pair  <unsigned int, T> & p2) : pair1(p2)
            {
            }
            //empty constructor.
            iterator(){

            }
            iterator& operator++() {
                pair1.first++;
                return *this;
            }

            auto &operator*()  {
                return pair1;
            }

            bool operator!=(const iterator &other)  {
                return (pair1.first!=other.pair1.first);
            }

        };
        auto begin() const {
            return iterator(std::pair <unsigned int, T> (0,a));
        }


        auto end()const {
            int i=1;
           for(int k=0;k<a.size();k++){
               i=i<<1;
           }

            return iterator(std::pair <unsigned int, T> (i,a));
        }



    };



//    template<typename T>powersetC<T> powerset(T x) {
//
//        return powersetC<T>(x);
//
//    }

//ostream operator
    template<typename T> ostream &operator<<(ostream &out, pair<unsigned int, T> &p)
    {
        string ans="";
        out << '{';
        bool first=true;
        auto startT = p.second.begin() ;
        auto endT = p.second.end();
        int i=1;
        while(startT!=endT)
        {
            if(i&p.first)
            {
                if(first)
                {
                    out<<*startT;
                    first=false;
                }
                else
                    out<<','<<*startT;
            }
            i=i<<1;
            ++startT;
        }
        out <<'}';
        return out;
    }

}
