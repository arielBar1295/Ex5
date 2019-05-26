#include<math.h>
#include <iostream>
#include <bits/stdc++.h>
#include <utility>

namespace itertools {


    template<typename T>
    class powerset {
        const T a;
        int size;
    public:
        powerset(const T& a1) : a(a1)
        {    int s=0;
            auto start=a.begin();
            while (start!=a.end()){
                ++start;
                s++;
            }
            size=s;
        }

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
            for(int k=0;k<size;k++){
                i=i<<1;
            }

            return iterator(std::pair <unsigned int, T> (i,a));
        }



    };

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
