package com.company;

import java.util.Scanner;

public class Menu {
    private final History letterManager;
    private final History packageManager;

    public Menu() {
        letterManager = new LetterManager();
        packageManager = new PackageManager();
    }

    /** Method prints menu */
    public void printMenu(){
        String input;
        Scanner scanner = new Scanner(System.in);

        do{
            System.out.println("MENU");
            System.out.println("Press 1 to send a letter.");
            System.out.println("Press 2 to send a package.");
            System.out.println("Press 3 to send a telegram.");
            System.out.println("Press 4 to change letter's recipient or change letter's file name.");
            System.out.println("Press 5 to change package's recipient or its description.");
            System.out.println("Press 6 to check if there is any letter for you.");
            System.out.println("Press 7 to check if there is any package for you.");
            System.out.println("Press 8 to cancel letter's shipment.");
            System.out.println("Press 9 to cancel package's shipment.");
            System.out.println("Press 0 to exit.");
            input = scanner.nextLine();
            if(isCorrect(input)){
                execute(convert(input));
            }
            else
                System.out.println("Choose the correct option!");

        }while(!input.equals("0"));
    }

    /** Method checks if option provided by the user is correct */
    private boolean isCorrect(String input){
        return input.matches("[0-9]{1}");
    }

    /** Method converts input provided by the user into int */
    private int convert(String input){
        return Integer.parseInt(input);
    }

    /** Method calls option selected by the user */
    private void execute(int option){
        switch (option) {
            case 1 -> letterManager.send();
            case 2 -> packageManager.send();
            case 3 -> {
                Telegram telegram = new Telegram();
                telegram.create();
                telegram.send();
            }
            case 4 -> letterManager.update();
            case 5 -> packageManager.update();
            case 6 -> letterManager.findSomething();
            case 7 -> packageManager.findSomething();
            case 8 -> letterManager.cancel();
            case 9 -> packageManager.cancel();
            case 0 -> {
                letterManager.save();
                packageManager.save();
                System.out.println("Thank you for using our services. See you soon! :)");
            }
            default -> System.out.println("Choose the correct option!");
        }
    }
}