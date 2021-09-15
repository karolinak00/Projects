package com.company;

import java.time.LocalDate;

/** Class extends Item. Package is responsible for creating and getting information about new objects (new packages) */
public class Package extends Item{
    private Weight weight; // package's weight
    private Message description; // package's description
    private double price; // cost of package's sending

    // constructors:
    public Package(User from, User to, String sendingDate, Weight weight, Message description, double price){
        super(from, to, sendingDate);
        this.weight = weight;
        this.description = description;
        this.price = price;
    }

    public Package(){
        super();
        scanPackage();
    }

    // getters:
    public String getDescription(){
        return description.get();
    }
    public double getWeight(){
        return weight.getWeight();
    }
    public double getPrice(){
        return this.price;
    }

    /** Method returns String that contains information about package */
    @Override
    public String get() {
        return  "Package sent to: " + getTo().getNameSurname() + "\n" + getTo().getAddress()
                + "\nfrom: " + getFrom().getNameSurname()  + "\n" + "Package weights " + weight.getWeight() + " kg and costs "
                + price + " PLN.\n" + "Package's description:\n" + description.get() + "\nPackage was sent on "
                + getSendingDate() + ". Receiving date: " + LocalDate.now() + ".\n\n";
    }


    // other methods:
    /** Method gets package's description from user */
    public void scanDescription(){
        System.out.println("Enter some information about what is in this package:");
        this.description = new Message();
    }

    /** Method gets package's weight from user */
    public void scanWeight(){
        System.out.println("Now enter some information about package:");
        this.weight = new Weight();
    }

    /** Method sets package's price which depends on package's weight */
    public void setPrice(){
        this.price = this.weight.getWeight() * 1.50;
        System.out.println("Sending this package costs " + price + "PLN.");
    }

    /** Method calls methods responsible for get information about package from user */
    public void scanPackage(){
        scanWeight();
        scanDescription();
        setPrice();
    }
}