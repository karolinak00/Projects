package com.company;

public class Street extends Data{

    public Street (String street){
        set(street);
    }

    public Street(){
        StreetPattern streetPattern = new StreetPattern();
        scan(streetPattern, "Enter street:", "Enter street in this format: street_name street_number or street_name street_number/apartment_number");
    }
}