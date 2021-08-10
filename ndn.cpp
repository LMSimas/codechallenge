
#include <iostream>

using namespace std;

#include "image.h"

void print_output(Image outp, int rLevel){
    
    if( outp.hasTiles() ){
        for(int i = 0; i < 4; i++){
            print_output(outp.tiles[i], rLevel + 1);
            //printf(outp.tiles[i].isBlack() ? "true" : "false");
        }
    }
    else{//if !hasTiles
        if( outp.isBlack() ) //if is black
            printf("%d Black ::  ", rLevel);
        else//if white
            printf("%d White ::  ", rLevel);
    }
    printf("\n");
}

Image merge(const Image& a, const Image& b) {
    Image imgResult(false, NULL); //malcriado

    if( a.hasTiles() ){
        if( b.hasTiles() ){
            //"Hard" case (both imgs have tiles)
            //allocate the imgResult.tiles
            imgResult.tiles = (Image*)malloc(sizeof(Image)*4);
            for(int i = 0; i < 4; i++){
                imgResult.tiles[i] = merge(a.tiles[i], b.tiles[i]);
            }
            imgResult.setBlack();
            return imgResult;
        }
        else{ //!b.hasTiles()
            if( b.isBlack() ){
                imgResult = a; //make sure it copies well TODO
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
    Image img1(false, NULL);
    Image img2(true, NULL);
    Image out1 = merge(img1, img2);
    printf("out1 -->");
    print_output(out1, 0);
    printf("\n\n");


    //soft case 2
    Image s1(false, NULL); //subImage
    Image s2 = Image(false, NULL);
    Image s3 = Image(false, NULL);
    Image s4 = Image(false, NULL);
    Image tile1[4] = {s1, s2, s3, s4};
    Image img3(false, tile1);
    printf("img3 -->\n");print_output(img3, 0);
    Image img4(true, NULL);
    printf("img4 -->\n");print_output(img4, 0);
    Image out2 = merge(img3, img4);
    printf("out2 -->\n");print_output(out2, 0);

    //soft case 3
    Image s11(true, NULL); //subImage
    Image s22 = Image(false, NULL);
    Image s33 = Image(false, NULL);
    Image s44 = Image(true, NULL);
    Image t11[4] = {s11, s22, s33, s44};
    Image img5(true, t11);
    Image img6(false, NULL);
    Image out3 = merge(img5,img6);
    printf("out3 -->\n");print_output(out3, 0);

    //Hard case 1
    Image q1 = Image(false, NULL); //subImage
    Image q2 = Image(false, NULL);
    Image q3 = Image(false, NULL);
    Image q4 = Image(false, tile1);//tile above

    Image tile00[4] = {q1, q2, q3, q4};
    Image q5 = Image(false, tile00);
    Image tile01 = Image(false, NULL);
    Image tile10 = Image(false, NULL);
    Image tile11 = Image(true, NULL);
    Image ftileUL[4] = {q5, tile01, tile10, tile11};
    Image img7 = Image(false, ftileUL);
    //--
    Image ftile2[4] = {s44, s22, s44, s22};
    Image img8 = Image(false, ftile2);
    Image out4 = merge(img7,img8);
    printf("out4 -->\n");print_output(out4, 0);

    //----Final Hard Case----||
    Image i1 = Image(false, NULL);
    Image t1[4] = {Image(true, NULL), Image(false, NULL), Image(false, NULL), Image(false, NULL)};
    Image i2 = Image(false, t1);
    //--
    Image i3 = Image(false, NULL);
    Image i4 = Image(true, NULL);
    Image t2[4] = {i1, i2, i3, i4};
    Image i5 = Image(false, t2);
    //--
    Image i6 = Image(false, NULL);
    Image i7 = Image(false, NULL);
    Image i8 = Image(false, NULL);
    Image t3[4] = {i5,i6,i7,i8};
    Image i9 = Image(false, t3);
    //--
    Image i10 = Image(false, NULL);
    Image i11 = Image(false, NULL);
    Image t4[4] = {Image(false, NULL), Image(false, NULL), Image(true, NULL), Image(true, NULL)};
    Image i12 = Image(false, t4);
    Image i13 = Image(true, NULL);
    Image t5[4] = {i10, i11, i12, i13};
    Image i14 = Image(false, t5);
    //--
    Image i15 = Image(false, NULL);
    Image i16 = Image(false, NULL);
    Image t6[4] = {i9,i14,i15, i16};
    Image imgA = Image(false, t6);

    //--ImgB
    Image e1 = Image(true, NULL);
    Image et1[4] = {Image(true, NULL), Image(false, NULL), Image(false, NULL), Image(true, NULL)};
    Image e2 = Image(false, et1);
    Image e3 = Image(true, NULL);
    Image e4 = Image(false, NULL);
    Image et2[4] = {e1,e2,e3,e4};
    Image e5 = Image(false, et2);
    //--
    Image e6 = Image(false, NULL);
    Image e7 = Image(true, NULL);
    Image e8 = Image(false, NULL);
    Image et3[4] = {e5, e6, e7, e8};
    Image imgB = Image(false, et3);

    //merge
    Image out5 = merge(imgA, imgB);
     printf("out5 -->\n");print_output(out5, 0);


    return 0;
}
