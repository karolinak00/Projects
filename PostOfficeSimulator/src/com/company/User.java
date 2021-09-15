package com.company;

public class User{

    private final NameSurname nameSurname;
    private final Address address;

    // constructors:
    public User(){
        this.nameSurname = new NameSurname();
        this.address = new Address();
    }

    public User(String nameSurname, String street, String zipCode,  String town, String country){
        this.nameSurname = new NameSurname(nameSurname);
        this.address = new Address(street, zipCode, town, country);
    }

    // getters:

    public String get(){
        return getNameSurname() + "\n" + getAddress();
    }

    public String getNameSurname(){
        return nameSurname.get();
    }

    public String getAddress(){
        return address.toString();
    }

    public String getAddressToFile(){
        return address.addressToFile();
    }

    // other methods:
    @Override
    public boolean equals(Object object) {
        if(object == null)
            return false;
        if(object instanceof User){
            User user = (User) object;
            return this.getNameSurname().equals(user.getNameSurname()) && this.getAddress().equals(user.getAddress());
        }
        return false;
    }
}