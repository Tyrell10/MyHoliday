#include <iostream>

class shape{
    protected:
        double width, height;
    public:
        void setWidth(double w){
            width = w;
        }
        void setHeight(double h){
            height = h;
        }
};
class Paintcost{
    public:
        double cost(double area){
            return area * 70;
        }
};
class rectangle : public shape, public Paintcost{
    public:
        double getArea(){
            return (width * height)/2;
        }
};

int main(){
    rectangle rect;
    int area;
    rect.setWidth(5.0);
    rect.setHeight(7.0);
    
    area = rect.getArea();
    std::cout << "Luas Segitiga = " << rect.getArea() << std::endl;
    std::cout << "Harga Cost    = $" << rect.cost(area) << std::endl;

    return 0;
}