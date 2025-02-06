package pkg1;
import java.security.cert.CollectionCertStoreParameters;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Collector;
import java.util.stream.Collectors;

class Population {
    public static void main(String  args[]){
        List<City>cities=Arrays.asList(
        new City(1, "Kabul", 1780000, "AFG"),
        new City(2, "Qandahar", 237500, "AFG"),
        new City(3, "Herat", 186800, "AFG"),
        new City(4, "Mazar-e-Sharif", 127800, "AFG"),
        new City(5, "Amsterdam", 731200, "NLD"),
        new City(6, "Rotterdam", 593321, "NLD"),
        new City(7, "Haag", 440900, "NLD"),
        new City(8, "Utrecht", 234323, "NLD"),
        new City(9, "Eindhoven", 201843, "NLD"),
        new City(10, "Tilburg", 193238, "NLD"),
        new City(11, "Groningen", 172701, "NLD"),
        new City(12, "Breda", 160398, "NLD"),
        new City(13, "Apeldoorn", 153491, "NLD"),
        new City(14, "Nijmegen", 152463, "NLD"),
        new City(15, "Enschede", 149544, "NLD"),
        new City(16, "Haarlem", 148772, "NLD"),
        new City(17, "Almere", 142465, "NLD"),
        new City(18, "Arnhem", 138020, "NLD"),
        new City(19, "Zaanstad", 135621, "NLD"),
        new City(20, "’s-Hertogenbosch", 129170, "NLD"),
        new City(21, "Amersfoort", 126270, "NLD"),
        new City(22, "Maastricht", 122087, "NLD"),
        new City(23, "Dordrecht", 119811, "NLD"),
        new City(24, "Leiden", 117196, "NLD"),
        new City(25, "Haarlemmermeer", 110722, "NLD"),
        new City(26, "Zoetermeer", 110214, "NLD"),
        new City(27, "Emmen", 105853, "NLD"),
        new City(28, "Zwolle", 105819, "NLD"),
        new City(29, "Ede", 101574, "NLD"),
        new City(30, "Delft", 95268, "NLD")
        );
        // for(City city:cities){
        //     System.out.println(city);
        // }

        List<Country>countries=Arrays.asList(
        new Country("ABW", "Aruba", "North America", 193, 103000, 828, 129),
        new Country("AFG", "Afghanistan", "Asia", 652090, 22720000, 5976, 1),
        new Country("AGO", "Angola", "Africa", 1246700, 12878000, 6648, 56),
        new Country("AIA", "Anguilla", "North America", 96, 8000, 63.2, 62),
        new Country("ALB", "Albania", "Europe", 28748, 3401200, 3205, 34),
        new Country("AND", "Andorra", "Europe", 468, 78000, 1630, 55),
        new Country("ANT", "Netherlands Antilles", "North America", 800, 217000, 1941, 33),
        new Country("ARE", "United Arab Emirates", "Asia", 83600, 2441000, 37966, 65),
        new Country("ARG", "Argentina", "South America", 2780400, 37032000, 340238, 69),
        new Country("ARM", "Armenia", "Asia", 29800, 3520000, 1813, 126),
        new Country("ASM", "American Samoa", "Oceania", 199, 68000, 334, 54),
        new Country("ATA", "Antarctica", "Antarctica", 13120000, 0, 0, -1),
        new Country("ATF", "French Southern territories", "Antarctica", 7780, 0, 0, -1),
        new Country("ATG", "Antigua and Barbuda", "North America", 442, 68000, 612, 63),
        new Country("AUS", "Australia", "Oceania", 7741220, 18886000, 351182, 135),
        new Country("AUT", "Austria", "Europe", 83859, 8091800, 211860, 1523),
        new Country("AZE", "Azerbaijan", "Asia", 86600, 7734000, 4127, 144),
        new Country("BDI", "Burundi", "Africa", 27834, 6695000, 903, 552),
        new Country("BEL", "Belgium", "Europe", 30518, 10239000, 249704, 179),
        new Country("BEN", "Benin", "Africa", 112622, 6097000, 2357, 187),
        new Country("BFA", "Burkina Faso", "Africa", 274000, 11937000, 2425, 549),
        new Country("BGD", "Bangladesh", "Asia", 143998, 129155000, 32852, 150),
        new Country("BGR", "Bulgaria", "Europe", 110994, 8190900, 12178, 539),
        new Country("BHR", "Bahrain", "Asia", 694, 617000, 6366, 149),
        new Country("BHS", "Bahamas", "North America", 13878, 307000, 3527, 148),
        new Country("BIH", "Bosnia and Herzegovina", "Europe", 51197, 3972000, 2841, 201),
        new Country("BLR", "Belarus", "Europe", 207600, 10236000, 13714, 3520),
        new Country("BLZ", "Belize", "North America", 22696, 241000, 630, 185),
        new Country("BMU", "Bermuda", "North America", 53, 65000, 2328, 191),
        new Country("BOL", "Bolivia", "South America", 1098581, 8329000, 8571, 194)
       );


       //task1
      Map<String, Optional<City>> maxPopulationCity = cities.stream()
        .collect(Collectors.groupingBy(
            city->city.getCountryCode(), 
            Collectors.maxBy(Comparator.comparingInt(city->city.getPopulation()))
        ));
        maxPopulationCity.forEach((county,city)->{
            System.out.println("Country Name "+county + " Highest Populated City "+ city.get().getName()+" " + city.get().getPopulation());
        });


        //task2
        Map<String,Optional<Country>>mostPopulatiedCountry=countries.stream().
        collect(Collectors.groupingBy(country->country.getContient(),Collectors.maxBy(Comparator.comparingInt(country->country.getPopulation()))));

        mostPopulatiedCountry.forEach((contient,country)->{
            System.out.println("Continent: " + contient + ", Most Populated Country: " + country.get().getName());
        });
        
        

        Optional<City> highestPopulatedCapital = countries.stream()
        .filter(country->country.getCapital()!=-1) 
        .map(country->cities.stream()
            .filter(city->city.getId()==country.getCapital())
            .findFirst()
            .orElse(null)
        )
        .filter(city->city!=null) 
        .max((city1,city2)->Integer.compare(city1.getPopulation(), city2.getPopulation()));

       System.out.println(highestPopulatedCapital.get().getName()+ " "+ highestPopulatedCapital.get().getPopulation());

    }
  
}