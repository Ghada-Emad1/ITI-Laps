package pkg1;
public class City {
    private int id;
    private String name;
    private int population;
    private String countryCode;

    City(int _id,String _name,int _population,String _countryCode){
        this.id=_id;
        this.name=_name;
        this.population=_population;
        this.countryCode=_countryCode;
    }
     
    public int getId(){
        return id;
    }
    public String getName(){ 
        return name;
    }
    public int getPopulation(){
        return population;
    }
    public String getCountryCode(){
        return countryCode;
    }

    @Override
    public String toString(){
        return id+" "+name+" "+population+" "+countryCode;
    }
    
}