#include <iostream>

using namespace std;

class Image{
    private:
        bool is_black_;
        Image * tiles;

    public:
        //Constructor
        Image(bool _is_black, Image * _tiles){
            is_black_ = _is_black;
            if(_tiles == NULL)
                return;
            else{
                tiles = (Image*)malloc(sizeof(Image)*4);//with 4 indexes
                for(int i = 0; i < 4; i++){
                    tiles[i] = _tiles[i];
                }
            }
        }
        //Getters
        bool hasTiles() const{
            if(tiles == NULL)
                return false;
            else
                return true;
        }
        
        bool isBlack() const{
            return is_black_;
        }
        
        Image getTiles(int index) const{
            return tiles[index];
        }
        
        //Setters
        void setBlack() {
            is_black_ = true;
        }

        void setWhite(){
            is_black_ = false;
        }
        
        //Methods
        void paintAllBlack(){
            if( tiles != NULL ){//if it has tiles
                for(int i = 0; i < 4; i++){
                    getTiles(i).paintAllBlack();
                }
            }
            setBlack();
        }
};

Image merge(const Image& a, const Image& b) {
    Image imgResult(false, NULL);//false and empty by default
    
    if( a.hasTiles() ){
        if( b.hasTiles() ){
            //"Hard" case (both imgs have tiles)
            for(int i = 0; i < 4; i++){
                imgResult.getTiles(i) = merge(a.getTiles(i), b.getTiles(i));
            }
            imgResult.setBlack();
            return imgResult;
        }
        else{
            return a;
        }
    }
    else{ // !a.hasTiles
        if( b.hasTiles() ){
            if( a.isBlack() ){
                imgResult = b;
                imgResult.paintAllBlack();
                return imgResult;
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