package com.company;

import java.util.Scanner;

public class Data implements DataMethods{

    private String element;
    public Data(){}

    @Override
    public String get() {
        return element;
    }

    protected void set(String element){
        this.element = element;
    }

    @Override
    public void scan(MyPattern pattern, String command, String error) {
        Scanner scanner = new Scanner(System.in);
        String el;
        boolean correct = false;
        do{
            System.out.println(command);
            el = scanner.nextLine();
            if(!pattern.check(el))
                System.out.println(error);
            else{
                set(el);
                correct = true;
            }
        }while(!correct);
    }
}
