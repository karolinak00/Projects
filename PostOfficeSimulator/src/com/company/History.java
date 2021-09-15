package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Arrays;

/** Abstrast class after which inherit PackageManager and LetterManager */
public abstract class History {

    /** Method reads data from file and saves it into Map
     * (for LetterManager class into 'letters', for PackageManager class into 'packages') */
    public void init(String p){
        Path path = Path.of(p);
        try(BufferedReader bufferedReader = Files.newBufferedReader(path)){
            String line = bufferedReader.readLine();
            while(line != null) {
                if(!line.startsWith("#")){
                    String[] elements = line.split(";");
                    lineToItem(elements);
                }
                line = bufferedReader.readLine();
            }
        }catch (IOException ioException){
            System.out.println("Something went wrong... " + Arrays.toString(ioException.getStackTrace()));
        }
    }

    /** Methods lets program's user enter information about sender or receiver */
    public User getUser(String command){
        System.out.println(command);
        User user = new User();
        return user;
    }

    /** Method finds all items (letters or packages) that are sent to specified person */

    public ArrayList<? extends Item> findItems(User user){
        ArrayList<Item> result = new ArrayList<>();
        if(recipientExists(user))
            result = new ArrayList<>(find(user));
        return result;
    }

    /** Method informs if there is any letter or package sent to specified person. If there is something, methods prints
     * these elements*/
    public void findSomething(){
        User user = getUser("I need some information about you.");
        ArrayList<? extends Item> items = new ArrayList<>(findItems(user));
        if(!items.isEmpty()){
            System.out.println("There's something for you:");
            for (Item item:items)
                System.out.println(item.get());
        } else
            System.out.println("There's nothing for you");
    }

    /** Method cancel letter's or package's shipment */
    public void cancel(){
        User user = getUser("I need some information about you.");
        if(senderExists(user)){
            delete(user);
        }
        else
            System.out.println("There's nothing to cancel");
    }

    /** Method lets user update letter's or package's information (method lets change item's recipient
     * or/and description/content) */
    public void update(){
        User user = getUser("I need some information about you.");
        if(senderExists(user)){
           change(user);
        }
        else
            System.out.println("There's nothing to update");
    }

    // abstract methods:
    public abstract void lineToItem(String[] elements);
    public abstract boolean recipientExists(User user);
    public abstract boolean senderExists(User user);
    public abstract ArrayList<? extends Item> find(User u);
    public abstract void add(User user, Item item);
    public abstract void send();
    public abstract void save();
    public abstract void delete(User user);
    public abstract void change(User user);
}