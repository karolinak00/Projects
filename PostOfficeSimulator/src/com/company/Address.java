package com.company;

public class Address {

    private final Street street;
    private final ZIPCode zipCode;
    private final Country country;
    private final Town town;

    public Address(){
        this.street = new Street();
        this.zipCode = new ZIPCode();
        this.town = new Town();
        this.country = new Country();
    }
    public Address(String street, String zipCode, String town, String country){
        this.street = new Street(street);
        this.zipCode = new ZIPCode(zipCode);
        this.town = new Town(town);
        this.country = new Country(country);
    }

    public String toString(){
        return street.get() + "\n" + zipCode.get() + " " + town.get() + "\n" + country.get();
    }
    public String addressToFile(){
        return street.get() + ";" + zipCode.get() + ";" + town.get() + ";" + country.get();
    }
}
