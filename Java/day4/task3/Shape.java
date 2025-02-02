package pkg3;
abstract class Shape{
    abstract void Draw();
}

class Rectangle extends Shape{
    @Override
    void Draw(){
        System.out.println("Rectangle Shape");
    }
}

class Circle extends Shape{
    @Override
    void Draw(){
        System.out.println("Circle Shape");
    }
}