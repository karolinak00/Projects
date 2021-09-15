package com.company;

public class NameSurname extends Data{

    public NameSurname (String nameSurname){
       set(nameSurname);
    }

    public NameSurname(){
        NameSurnamePattern nameSurnamePattern = new NameSurnamePattern();
        scan(nameSurnamePattern, "Enter name and surname:", "You have to enter first name and surname (or surnames in this format: first_surname-second_surname)" );
    }
}