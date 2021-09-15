package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Arrays;
import java.util.Scanner;

/** Class extends Item. Letter is responsible for creating and getting information about new objects (new letters) */
public class Letter extends Item{
    private String path; // path to file that contains letter

    // constructors:
    public Letter(){
        super();
        scanPath();
    }
    public Letter(User from, User to, String sendingDate, String path){
        super(from, to, sendingDate);
        setPath(path);
    }

    //getters:
    /** Method returns String that contains information about letter */
    @Override
    public String get() {
        return "Sender:\n" + getTo().get() + "\n\nRecipient:\n" + getFrom().get()  + "\\nContent:" + loadLetter(path) + "\n\n";
    }

    public String getPath(){
        return this.path;
    }

    // setters:
    public void setPath(String path){
        this.path = path;
    }

    // other methods:
    /** Method gets path to file that contains letter from user */
    public void scanPath(){
        Scanner scanner = new Scanner(System.in);
        String p;
        boolean correct = false;
        do{
            System.out.println("Enter name of the file which contains letter:");
            p = scanner.nextLine();
            if(p.matches("[A-Za-z0-9]+\\.txt")){
                setPath(p);
                correct = true;
            }
            else
                System.out.println("Your file must be text file (with .txt extension)!");
        }while(!correct);
    }

    /** Method reads letter from file and returns String that contains letter's content */
    public String loadLetter(String p){
        StringBuilder stringBuilder = new StringBuilder();
        Path path = Path.of(p);
        try(BufferedReader bufferedReader = Files.newBufferedReader(path)){
            String line = bufferedReader.readLine();
            while(line != null){
                stringBuilder.append(line).append("\n");
                line = bufferedReader.readLine();
            }

        }catch (IOException ioException){
            System.out.println("Something went wrong... " + Arrays.toString(ioException.getStackTrace()));
        }
        return stringBuilder.toString();
    }
}