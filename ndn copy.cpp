
#include <iostream>

using namespace std;

#include "object.h"

void print_output(Image outp){
    printf("...printfunct\n");
    if( outp.isBlack() ) //if is black
        printf("Black ::  ");
    else//if white
        printf("White ::  ");


    if( outp.hasTiles() ){
        for(int i = 0; i < 4; i++){
            printf(outp.getTiles(i).isBlack() ? "true\n" : "false\n");
        }
    }
    printf("\n");
}

Image merge(const Image& a, const Image& b) {
    Image imgResult = Image(false, NULL);//false and empty by default


    if( a.hasTiles() ){
        if( b.hasTiles() ){
            //"Hard" case (both imgs have tiles)
            for(int i = 0; i < 4; i++){
                imgResult.getTiles(i) = merge(a.getTiles(i), b.getTiles(i));
            }
            imgResult.setBlack();
            return imgResult;
        }
        else{ //!b.hasTiles()
            if( b.isBlack() ){
                imgResult = a.getCopy();
                imgResult.paintAllBlack();
                return imgResult;
            }
            else{// !b.isBlack()
                return a;
            }
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
    //soft case 1
    Image* img1 = new Image(false, NULL);
    Image* img2 = new Image(true, NULL);
    Image out1 = merge(*img1, *img2);
    printf("out1 -->");
    print_output(out1);
    printf("\n\n");

    //soft case 2
    Image* s1 = new Image(false, NULL); //subImage
    Image* s2 = new Image(false, NULL);
    Image* s3 = new Image(false, NULL);
    Image* s4 = new Image(false, NULL);
    Image* tile1[4] = {s1, s2, s3, s4};
    Image* img3 = new Image(false, *tile1);
    printf("img3 -->");print_output(*img3);
    Image* img4 = new Image(true, NULL);
    printf("img4 -->");print_output(*img4);
    Image out2 = merge(*img3, *img4);
    printf("out2 -->");printf("%b\n", out2.isBlack());




    return 0;
}
