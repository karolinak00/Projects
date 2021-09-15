package com.company;

public class Town extends  Data{

    public Town (String town){
        set(town);
    }

    public Town(){
        CountryPattern countryPattern = new CountryPattern();
        scan(countryPattern, "Enter town:", "You entered wrong town!");
    }
}