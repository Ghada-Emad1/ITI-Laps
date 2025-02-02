package pkg4;
public interface Complex<T>{
    T getReal();
    T getImag();
    Complex <T> add(Complex <T> num);
    Complex <T> subtract(Complex <T>num);
    Complex <T> product(Complex <T> num);
    Complex <T> div(Complex <T> num);
}

