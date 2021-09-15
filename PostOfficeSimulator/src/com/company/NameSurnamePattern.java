package com.company;

public class NameSurnamePattern extends MyPattern{
    public NameSurnamePattern(){
        setPattern("[A-Z][a-z]{1,20} [A-Z][a-z]{1,20}(-[A-Z][a-z]{1,20})?");
    }
}
