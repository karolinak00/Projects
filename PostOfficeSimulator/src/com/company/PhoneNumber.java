package com.company;

public class PhoneNumber extends Data{

    public PhoneNumber (String phoneNumber){
        set(phoneNumber);
    }

    public PhoneNumber(){
        PhoneNumberPattern phoneNumberPattern = new PhoneNumberPattern();
        scan(phoneNumberPattern, "Enter phone number:", "You entered wrong number. Remember: Phone number contains 9 digits without any white character." );
    }
}