package pkg2;
import java.util.function.Function;
public class FormulaSolution implements Function<double[], String> {
        @Override
        public String apply(double[]params) {
            double a=params[0];
            double b=params[1];
            double c=params[2];
            if (a==0) {
                return "Value of a can't be 0";  
            }
            double d=(b*b)-(4*a*c);
            double r= -b/(2.0*a);
            if (d>0) {
                double sqrtD=Math.sqrt(d)/ (2.0 * a);
                double r1=(-b+sqrtD);
                double r2=(-b-sqrtD);
                return "The roots are real and distinct: Root1 = "+r1+", Root 2 = "+ r2;
            } else if (d==0) {
            	return "The roots are real and equal: Root = "+r;
            } else {
            	double imaginary=Math.sqrt(-d)/(2 * a);
            	return "The roots are complex: Root 1 = "+r+" + "+imaginary+"i, Root 2 = "+r+" - "+imaginary+ "i";
            }
        }
    }

   
