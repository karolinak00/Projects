package com.company;

import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.*;

/** Class extends class History. LetterManager is responsible for saving and processing data related to letters' shipment */
class LetterManager extends History{
    private HashMap<User, Letter> letters;
    private final String lettersRegisterPath = "lettersRegistry.csv";

    // constructor:
    public LetterManager(){
        super();
        this.letters = new HashMap<>();
        init(lettersRegisterPath);
    }

    // other methods:
    /** Method lets convert information from file (String) into object (Letter) */
    @Override
    public void lineToItem(String[] elements) {
        String nameSurname1, street1, zipCode1, town1, country1, nameSurname2, street2, zipCode2,
                town2, country2, sendingDate, pathToFile;
        nameSurname1 = elements[0];
        street1 = elements[1];
        zipCode1 = elements[2];
        town1 = elements[3];
        country1 = elements[4];
        nameSurname2 = elements[5];
        street2 = elements[6];
        zipCode2 = elements[7];
        town2 = elements[8];
        country2 = elements[9];
        sendingDate = elements[10];
        pathToFile = elements[11];
        User from = new User(nameSurname1, street1, zipCode1, town1, country1);
        User to = new User(nameSurname2, street2, zipCode2, town2, country2);
        Letter letter = new Letter(from, to, sendingDate, pathToFile);
        add(to, letter);
    }

    /** Method checks if in map named "letters" exists specified recipient */
    @Override
    public boolean recipientExists(User user) {
        for (User u:letters.keySet()) {
            if (u.equals(user))
                return true;
        }
        return false;
    }

    /** Method checks if in map named "letters" exists specified sender */
    @Override
    public boolean senderExists(User user) {
        for (Letter l:letters.values()) {
            if (l.getFrom().equals(user))
                return true;
        }
        return false;
    }

    /** Method checks if in map named "letters" exists any letter for specified user */
    @Override
    public ArrayList<Letter> find(User u){
        ArrayList<Letter> result = new ArrayList<>();
        for (User user:letters.keySet()) {
            if(user.equals(u)) {
                result.add(letters.get(user));
            }
        }
        return result;
    }

    /** Method adds record into map named "letters" */
    @Override
    public void add(User user, Item item){
        letters.put(user, (Letter)item);
    }

    /** Method 'sends' letter (i.e. lets user create new Letter and adds it into map 'letters') */
    @Override
    public void send() {
        Letter letter = new Letter();
        add(letter.getTo(), letter);
        System.out.println("Letter sent successfully");
    }

    /** Method saves all records from map named "letters" into file */
    @Override
    public void save() {
        StringBuilder stringBuilder = new StringBuilder();
        Path path = Path.of(lettersRegisterPath);
        try (BufferedWriter bufferedWriter = Files.newBufferedWriter(path)) {
            String lettersRegisterHeader = "#sender_nameSurname;sender_street;sender_zipCode;sender_town;sender_country;receiver_nameSurname;receiver_street;receiver_zipCode;receiver_town;receiver_country;sending_date;path";
            stringBuilder.append(lettersRegisterHeader).append("\n");
            for (Letter l : letters.values())
                stringBuilder.append(l.getFrom().getNameSurname()).append(";").append(l.getFrom().getAddressToFile()).append(";").append(l.getTo().getNameSurname()).append(";").append(l.getTo().getAddressToFile()).append(";").append(l.getSendingDate()).append(";").append(l.getPath()).append("\n");
            bufferedWriter.write(stringBuilder.toString());
            letters.clear();
        } catch (IOException ioException) {
            System.out.println("Something went wrong... " + Arrays.toString(ioException.getStackTrace()));
        }
    }

    /** Method lets specified user delete letters that have been sent by this user */
    @Override
    public void delete(User u) {
        for(Iterator<Letter> iterator = letters.values().iterator(); iterator.hasNext(); ) {
            Letter key = iterator.next();
            if(key.getFrom().equals(u)) {
                System.out.println("You sent this letter:\n");
                System.out.println(key.get());
                System.out.println("Do you want to delete it? If yes, press 'Y'.");
                Scanner scanner = new Scanner(System.in);
                String input = scanner.nextLine();
                if(input.toUpperCase(Locale.ROOT).equals("Y")){
                    iterator.remove();
                    System.out.println("Letter deleted successfully.");
                }
            }
        }
    }

    /** Method lets specified user change letters' recipient or/and paths to files that contains these letters */
    @Override
    public void change(User u) {
        for(Iterator<Letter> iterator = letters.values().iterator(); iterator.hasNext(); ) {
            Letter key = iterator.next();
            if(key.getFrom().equals(u)) {
                System.out.println("You sent this letter:\n");
                System.out.println(key.get());
                System.out.println("Do you want to change something? If yes, press 'Y'.");
                Scanner scanner = new Scanner(System.in);
                String input = scanner.nextLine();
                if(input.toUpperCase(Locale.ROOT).equals("Y")){
                    System.out.println("Do you want to change letter's recipient? If yes, press 'Y'.");
                    input = scanner.nextLine();
                    if(input.toUpperCase(Locale.ROOT).equals("Y")) {
                        User user = getUser("I need some information about new recipient.");
                        key.setTo(user);
                    }
                    System.out.println("Do you want to change letter's file name? If yes, press 'Y'.");
                    input = scanner.nextLine();
                    if(input.toUpperCase(Locale.ROOT).equals("Y"))
                        key.scanPath();
                    System.out.println("Package's information updated successfully:\n");
                    System.out.println(key.get());
                }
            }
        }
    }
}
