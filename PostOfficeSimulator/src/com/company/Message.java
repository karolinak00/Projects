package com.company;

public class Message extends Data{

    public Message (String message){
        set(message);
    }

    public Message(){
        MessagePattern messagePattern = new MessagePattern();
        scan(messagePattern, "Enter message:", "Your message is empty or is too long. Your message size must be <1, 50> characters.");
    }
}