package pkg4;
public class DoubleComplex implements Complex<Double>{
    double real;
    double imag;

    public DoubleComplex(double _real,double _imag){
        this.real=_real;
        this.imag=_imag;
    }
    @Override
    public Double getReal(){
        return real;
    }

    @Override 
    public Double getImag(){
        return imag;
    }

    @Override
    public Complex <Double>add(Complex<Double>num){
        Complex<Double>res=new DoubleComplex(this.real+num.getReal(),this.imag+num.getImag());
        return res;
    }

    @Override
    public Complex<Double>subtract(Complex<Double>num){
        Complex <Double>res=new DoubleComplex(this.real-num.getReal(), this.imag-num.getImag());
        return res;
    }

    @Override
    public Complex<Double>product(Complex<Double>num){
        Complex <Double> res=new DoubleComplex(this.real*num.getReal(),this.imag*num.getImag());
        return res; 
    }

    @Override
    public Complex <Double>div(Complex <Double> num){
       double demon=num.getReal()*num.getReal()+num.getImag()*num.getImag();
       Complex <Double>res=new DoubleComplex((this.real*num.getReal()+this.imag*num.getImag())/demon,(this.imag*num.getReal()-this.real*num.getImag()/demon) );
       return res;

    }

    @Override
    public String toString() {
        if(imag>0){
            return real+" + "+imag +"i";
        }else if (imag<0){
            return real+" "+imag+"i";
        }else{
            return real +" ";
        }
        
    }
    
}