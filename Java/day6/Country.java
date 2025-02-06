package pkg1;
public class Country{
    private String code;
    private String name;
    private String continent;
    private double surfaceArea;
    private int population;
    private double gnp;
    private int capital;

    Country(String _code,String _name,String _contin,double _surfaceArea,int _population,double _gnp,int _capital){
        this.code=_code;
        this.name=_name;
        this.continent=_contin;
        this.surfaceArea=_surfaceArea;
        this.population=_population;
        this.gnp=_gnp;
        this.capital=_capital;
        
    }
    public String getCode(){return code; }
    public String getName(){return name;}
    public String getContient(){return continent;}
    public double getSurfaceArea(){return surfaceArea;}
    public int getPopulation(){return population;}
    public double getGnp(){return gnp;}
    public int getCapital(){return capital;}

    @Override
    public String toString(){
        return code+" "+name+" "+continent+" "+surfaceArea+" "+population+" "+gnp+" "+capital;
    }
}