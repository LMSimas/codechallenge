#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <bitset>
#include <vector>
#include <memory>
using namespace std;

class Image{
    private:
        
        
    public:
        bool is_black_;
        Image * tiles = NULL;

        //Constructors
        Image(bool _is_black, Image * _tiles);
        Image(const Image& img);
        Image();
        Image(const Image& tile0, const Image& tile1, const Image& tile2, const Image& tile3);
        //Getters
        bool hasTiles() const;

        bool isBlack() const;

        Image getTiles(int index);

        //Setters
        void setBlack();

        void setWhite();

        //Methods
        void paintAllBlack();
};

#endif // OBJECT_H 