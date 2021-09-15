package com.company;

import java.time.LocalDate;

public abstract class Item {
    private User from, to;
    private String sendingDate;

    // constructors:
    public Item(User from, User to, String sendingDate){
        setFrom(from);
        setTo(to);
        setSendingDate(sendingDate);
    }

    public Item(){
        scan();
    }

    // getters:
    public User getFrom() {
        return from;
    }
    public User getTo() {
        return to;
    }
    public String getSendingDate() {
        return sendingDate;
    }

   // setters:
    public void setSendingDate(String sendingDate) {
        this.sendingDate = LocalDate.now().toString();
    }
    public void setTo(User to) {
        this.to = to;
    }
    public void setFrom(User from) {
        this.from = from;
    }

    // other methods:
    /** Method gets information about sender and receiver from user and calls method that sets sending date */
    public void scan(){
        System.out.println("I need some information about You.");
        User from = new User();
        setFrom(from);
        System.out.println("Who is recipient of this package?");
        User to = new User();
        setTo(to);
        setSendingDate(LocalDate.now().toString());
    }

    // abstract methods:
    public abstract String get();
}