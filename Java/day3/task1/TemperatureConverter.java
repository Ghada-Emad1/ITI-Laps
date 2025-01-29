package pkg1;
import java.util.function.Function;
public class TemperatureConverter implements Function<Float, Float> {
    @Override
    public Float apply(Float t) {
        return (t*9/5)+32;
    }
}