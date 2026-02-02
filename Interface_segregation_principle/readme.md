# ISP (Integration Segregation principle)

## It is one of the pillar of design pattern

### It states that:
    1. Many client specific interface are better then one general purpose interface.
    2. Client should not be forced to implement methods they don't need.

## Explaination
    Lets say we are implementing classes for shapes.
    
    Method 1(violating ISP):
        
        class shapes{
            area();
            volume();
        }

        class square : public shapes{
            area();
            volume(); // not applicable in 2d shapes
        }

        class rectangle : public shapes{
            area();
            volume(); // not applicable in 2d shapes
        }

        class cube : public shapes{
            area();
            volume();
        }

    Method 2(following ISP):
        
        class 2dShape{
            area();
        }   
        
        class 3dShape{
            area();
            volume();
        }

        class sqaure : public 2dshape{
            area();
        }

        class cube : public 3dshape{
            area();
            volume();
        }