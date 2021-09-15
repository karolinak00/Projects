package com.company;

public class ZIPCode extends Data{

    public ZIPCode (String zipCode){
        set(zipCode);
    }

    public ZIPCode(){
        ZIPCodePattern zipCodePattern = new ZIPCodePattern();
        scan(zipCodePattern, "Enter ZIP Code:", "Enter ZIP Code in this format: XX-XXX");
    }
}
