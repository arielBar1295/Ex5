#include <iostream>
#include <utility>
#include <bits/stdc++.h>
#include<math.h>
//using namespace std;
namespace itertools {


    template<typename T>
    class powersetC {
        const T x;
        //uint size;
    public:
        powersetC(const T& a) : x(a)
        {}

        powersetC(){

        }

        class iterator {
            std::pair <unsigned int, T> powerPair;


        public:
            iterator(const std::pair  <unsigned int, T> & pP) : powerPair( pP)
            {
            }

            iterator(){

            }

            auto &operator*()  {
                return powerPair;
            }

            iterator& operator++() {
                powerPair.first++;
                return *this;
            }

            const iterator& operator++(int) {
                iterator tmp= *this;
                powerPair.first++;
                return tmp;
            }

            bool operator!=(const iterator &other)  {
                return (powerPair.first!=other.powerPair.first);
            }

        };

        // iterator begin() {
        auto begin() const {
            return iterator(std::pair <unsigned int, T> (0,x));
        }

        // iterator end() {
        auto end()const {
            int j=1;

            auto it =x.begin();
            while(it!=x.end())
            {
                j = j<<1;
                ++it;
            }

            return iterator(std::pair <unsigned int, T> (j,x));
        }



    };



    template<typename T>powersetC<T> powerset(T x) {

        return powersetC<T>(x);

    }

    template<typename T> ostream &operator<<(ostream &output, pair<unsigned int, T> &p)
    {
        auto start = p.second.begin() ;
        auto end = p.second.end();
        string str ="";
        bool firstC=true;
        output << '{';
        int i=1;
        while(start!=end)
        {
            if(i&p.first)
            {
                if(firstC)
                {
                    output<<*start;
                    firstC=false;
                }
                else
                    output<<','<<*start;
            }
            i=i<<1;
            ++start;
        }
        output <<'}';
        return output;
    }

}
