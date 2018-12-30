#include <iostream>

class Max{
    private:
    int *x, *y;

    public:
    Max();
    ~Max();
    void setMax(int a, int b);
    
    inline int getMax();
};
Max::Max(){
    std::cout << "class is being created" << std::endl;
    x = new int;
    y = new int;
}
Max::~Max(){
    std::cout << "class is being deleted" << std::endl;
    delete x;
    delete y;
}
void Max::setMax(int a, int b){
    *x = a;
    *y = b;
}
int Max::getMax(){
    return (*x > *y)? *x:*y;
}

int main(){
    Max *max = new Max();
    max->setMax(5,10);
    std::cout << "max(5,10): " << max->getMax() << std::endl;

    delete max;
    return 0;
}