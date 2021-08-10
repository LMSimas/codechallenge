#include "image.h"

    //Constructors
    Image::Image(bool _is_black, Image *_tiles){
        is_black_ = _is_black;
        if( _tiles == NULL){} //if empty

        else{
            tiles = (Image*)malloc(sizeof(Image)*4);//create 4 Image postitions
            for(int i = 0; i < 4; i++){
                tiles[i] = _tiles[i];
            }
        }
    }
    Image::Image(){
        is_black_ = false;
        //tiles = (Image*)malloc(sizeof(Image)*4);
    }
    Image::Image(const Image& img){
        is_black_ = img.is_black_;
        
        if(img.hasTiles()){
            tiles = (Image*)malloc(sizeof(Image)*4);
            for(int i = 0; i < 4; i++)
                tiles[i] = Image(img.tiles[i]);
        }
    }
    Image::Image(const Image& tile0, const Image& tile1, const Image& tile2, const Image& tile3){
        is_black_ = false;
        
        //if(img.hasTiles()){
            tiles = (Image*)malloc(sizeof(Image)*4);
            tiles[0] = Image(tile0);
            tiles[1] = Image(tile1);
            tiles[2] = Image(tile2);
            tiles[3] = Image(tile3);
        //}
    }
    //Getters
    bool Image::hasTiles() const{
        if( tiles == NULL)
            return false;
        else
            return true;
    }

    bool Image::isBlack() const{
        return is_black_;
    }

    //Setters
    void Image::setBlack(){
        is_black_ = true;
    }

    void Image::setWhite(){
        is_black_ = false;
    }

    //Methods
    void Image::paintAllBlack(){
        if( tiles != NULL ){//if it has tiles
            for(int i = 0; i < 4; i++){
                tiles[i].paintAllBlack();
            }
        }
        setBlack();
    }