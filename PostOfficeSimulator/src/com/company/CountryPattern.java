package com.company;

public class CountryPattern extends MyPattern{
    public CountryPattern(){
        setPattern("([A-Z][a-z]{1,20}){1}( [A-Z][a-z]{1,20})?( ([a-z])* [A-z][a-z]{1,20})*");
    }
}
