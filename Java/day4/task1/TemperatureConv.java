package pkg1;
import java.util.function.Function;
public class TemperatureConv{

    public class CeliususToFarh implements Function<Float,Float>{
      @Override
      public Float apply (Float t){
        return (t*9/5)+32;
      }
    }
}