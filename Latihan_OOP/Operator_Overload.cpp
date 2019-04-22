#include <iostream>

class Box{
    private:
        double length, breadth, height;
    public:
        void setLength(double l){
            length = l;
        }
        void setBreadth(double b){
            breadth = b;
        }
        void setHeight(double h){
            height = h;
        }
        double getVolume(){
            return length * breadth * height;
        }
    // overload + operator to add two object
    Box operator+(const Box &b){
        Box box;
        box.length = this->length + b.length;
        box.breadth = this->breadth + b.breadth;
        box.height = this->height + b.height;
        return box;
    }
};

int main(){
    Box Box1, Box2, Box3;
    double volume = 0;

    //set Box1
    Box1.setLength(5.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(10.0);
    volume = Box1.getVolume();
    std::cout << "Volume = " << volume << std::endl;

    //set Box2
    Box2.setLength(10.0);
    Box2.setBreadth(5.0);
    Box2.setHeight(5.0);
    volume = Box2.getVolume();
    std::cout << "Volume = " << volume << std::endl;

    //overload operator
    Box3 = Box1 + Box2;
    volume = Box3.getVolume();
    std::cout << "Volume = " << volume << std::endl;

    return 0;
}