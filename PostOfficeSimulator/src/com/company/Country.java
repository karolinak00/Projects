package com.company;

public class Country extends Data{

    public Country (String country){
        set(country);
    }

    public Country(){
        CountryPattern countryPattern = new CountryPattern();
        scan(countryPattern, "Enter country:", "You entered wrong country!");
    }
}