#include "../include/MathUtils.hpp"
#include <cmath>

#define const1 0.99321
#define const2 1.9947

#define weight1 1.35 // 0 to 6 months
#define weight2 0.85 // 6 to 12 months
#define weight3 0.45 // 12 to any months

int calculateBWSrank(int actualRank, int noBadges, int sizeofArrayN1, int sizeofArrayN2, int sizeofArrayN3) {
        
        if (noBadges == 0){
            return actualRank;
        } else{
            return pow(actualRank, 
                        pow(const1, noBadges*(const2+(
                                (sizeofArrayN1*weight1)+
                                (sizeofArrayN2*weight2)+
                                (sizeofArrayN3*weight3)))));
        }
}

