
#define PI 3.14159265 
#include <iostream>
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) {
    double length;
    struct vector {
        double x, y, len;
    };
    struct coordinates { //входные данные
        int x , y;
    };
    struct angs { // выходные данные
        double a, b, c, fi;
    };
    struct hand { //параметры манипулятора
        double height, l1, l2, l3, quality = 1;
    };
    struct limbs { 
        vector vec;
        double x, y;
        double ArgMin,ArgMax;
    };

    limbs limb1;
    limbs limb3;
    limbs limb2;
    angs angs;

    hand hand;
    hand.height = 30;
    hand.l1 = 300;
    hand.l2 = 300;
    hand.l3 = 300;

    coordinates obj;
    obj.x = atoi(argv[1]);
    obj.y = atoi(argv[2]);

    length = sqrt(pow(obj.x, 2) + pow(obj.y, 2)); //расстояние от манипулятора до объекта

    for (int i = 0; i < 90; i++) { 
        for (int j = 0; j < 180; j++) {

            limb1.x = (cos(i * PI / 180) * hand.l1);
            limb1.y = (sin(i * PI / 180) * hand.l1 + hand.height);
            limb3.x = (cos(j * PI / 180) * hand.l3 + length);
            limb3.y = (sin(j * PI / 180) * hand.l3);

            limb2.vec.x = limb3.x - limb1.x;
            limb2.vec.y = limb3.y - limb1.y;
            limb2.vec.len = sqrt(pow(limb2.vec.x, 2) + pow(limb2.vec.y, 2));

            if (fabs(limb2.vec.len - hand.l3) < 10) {

                limb1.vec.x = limb1.x;
                limb1.vec.y = limb1.y - hand.height;
                limb1.vec.len = sqrt(pow(limb1.vec.x, 2) + pow(limb1.vec.y, 2));

                limb3.vec.x = length - limb3.x;
                limb3.vec.y = -limb3.y;
                limb3.vec.len = sqrt(pow(limb3.vec.x, 2) + pow(limb3.vec.y, 2));

                angs.a = i;
                angs.b = acos((limb1.vec.x * limb2.vec.x + limb1.vec.y * limb2.vec.y) / limb1.vec.len * limb2.vec.len);
                angs.c = acos((limb2.vec.x * limb3.vec.x + limb2.vec.y * limb3.vec.y) / limb2.vec.len * limb3.vec.len);
            }
        }
    }

    
    angs.fi = atan(obj.y / obj.x);
    printf("%f, %f,  %f,  %f,  %f", length, angs.fi, angs.a, angs.b,angs.c);

}

