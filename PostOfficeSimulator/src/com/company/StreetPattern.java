package com.company;

public class StreetPattern extends MyPattern{
    public StreetPattern(){
        setPattern("(([0-9]*)?([A-Z]*[a-z]{1,20})?){1}( [A-Z]*[a-z]*)*( ([a-z])* [A-z]*[a-z]{1,20})* [0-9]*[A-Za-z]?(/([0-9]*))?");
    }
}
