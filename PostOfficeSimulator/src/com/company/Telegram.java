package com.company;

public class Telegram {
    private PhoneNumber phoneNumber;
    private Message message;
    private NameSurname nameSurname;

    public Telegram() {}

    /** Method gets information from user */
    public void create(){
        System.out.println("I need phone number to which the telegram will be sent.");
        phoneNumber = new PhoneNumber();
        System.out.println("OK. Now I need message which will be sent.");
        message = new Message();
        System.out.println("Finally, You have to sign.");
        nameSurname = new NameSurname();
    }

    /** Methods "sends" telegram (prints telegram on the screen) */
    public void send(){
        System.out.println("New telegram has been sent to: " + phoneNumber.get());
        System.out.println("From: " + nameSurname.get());
        System.out.println("Message:\n " + message.get() + "\n");
    }
}
