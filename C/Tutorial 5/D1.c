// A structure called circle is defined below. The structure consists of  the radius of the circle
// and the (x,y) coordinates of its centre.
// struct circle {
// double radius;
// double x;
// double y;
// };
// (a)  Implement the function intersect() that returns 1 if two circles intersect, and 0
// otherwise. Two circles intersect when the distance between their centres is less than or
// equal to the sum of their radii. The function prototype is given below:
// int intersect(struct circle c1, struct circle c2);
// (b)  Implement the function contain() that returns 1 if  c1 contains c2, i.e. circle c2 is found
// inside circle c1.  Otherwise, the function returns 0.  Circle c1 contains circle c2 when the
// radius of c1 is larger than or equal to the sum of the radius of c2 and the distance
// between the centres of c1 and c2. The function prototype is given below:
// int contain(struct circle *c1, struct circle *c2);

#include <stdio.h>
#include <math.h>
int intersect(struct circle c1, struct circle c2);
struct circle
{
    double radius;
    double x;
    double y;
};

int main()
{
    
}

int intersect(struct circle c1, struct circle c2)
{
    if ((sqrt(pow((c2.x - c1.x),2) + sqrt(pow((c2.y - c1.y),2))) > (c2.radius - c1.radius)))
    {
        return 1;
    }
    return 0;
}