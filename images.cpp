/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Image{
    public:
        bool is_black_;
        Image * tiles;
        
        bool hasTiles() const{
            if(tiles == NULL)
                return false;
            else
                return true;
        }
        
        bool isBlack() const{
            return is_black_;
        }
        
        void painted(){
            if( tiles != NULL ){//
                for(int i = 0; i < 4; i++){
                    tiles[i].painted();
                }
            }
            is_black_ = true;
        }
};

Image merge(const Image& a, const Image& b) {
    Image imgResult;
    
    if( a.hasTiles() ){
        if( b.hasTiles() ){
            //"Hard" case (both imgs have tiles)
            for(int i = 0; i < 4; i++){
                imgResult.tiles[i] = merge(a.tiles[i], b.tiles[i]);
            }
        }
        else{
            return a;
        }
    }
    else{// ! a.hasTiles
        if( b.hasTiles() ){
            if( a.isBlack() ){
                b.painted();
                return imgResult = b;
            }
                
            else
                return b;
        }
        else{
            if( a.isBlack() )
                return a;
            else
                return b;
        }
    }
    
}
int main()
{
    cout<<"Hello World";

    return 0;
}
