package com.company;

import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.*;

/** Class extends class History. PackageManager is responsible for saving and processing data related to packages' shipment */
public class PackageManager extends History{
    private HashMap<User, Package> packages;
    private final String packageRegisterPath = "packageRegistry.csv";

    // constructor:
    public PackageManager(){
        super();
        this.packages = new HashMap<>();
        init(packageRegisterPath);
    }

    // other methods:
    /** Method lets convert information from file (String) into object (Package) */
    @Override
    public void lineToItem(String[] elements) {
        String nameSurname1, street1, zipCode1, town1, country1, nameSurname2, street2, zipCode2,
                town2, country2, sendingDate, description;
        double weight, price;
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
        weight = Double.parseDouble(elements[11]);
        description = elements[12];
        price = Double.parseDouble(elements[13]);
        User from = new User(nameSurname1, street1, zipCode1, town1, country1);
        User to = new User(nameSurname2, street2, zipCode2, town2, country2);
        Weight w = new Weight(weight);
        Message d = new Message(description);
        Package p = new Package(from, to, sendingDate, w, d, price);
        add(to, p);
    }

    /** Method checks if in map 'packages' exists specified recipient */
    @Override
    public boolean recipientExists(User user) {
        for (User u:packages.keySet()) {
            if (u.equals(user))
                return true;
        }
        return false;
    }

    /** Method checks if in map 'packages' exists specified sender */
    @Override
    public boolean senderExists(User user) {
        for (Package p:packages.values()) {
            if (p.getFrom().equals(user))
                return true;
        }
        return false;
    }

    /** Method checks if in map named "packages" exists any package for specified user */
    @Override
    public ArrayList<Package> find(User u){
        ArrayList<Package> result = new ArrayList<>();
        for (User user:packages.keySet()) {
            if(user.equals(u)) {
                result.add(packages.get(user));
            }
        }
        return result;
    }

    /** Method adds record into map named "packages" */
    @Override
    public void add(User user, Item item){
       packages.put(user, (Package) item);
    }

    /** Method 'sends' package (i.e. lets user create new Package and adds it into map named "packages") */
    @Override
    public void send() {
        Package p = new Package();
        add(p.getTo(), p);
        System.out.println("Package sent successfully");
    }

    /** Method saves all records from map named "packages" into file */
    @Override
    public void save() {
        StringBuilder stringBuilder = new StringBuilder();
        Path path = Path.of(packageRegisterPath);
        try(BufferedWriter bufferedWriter = Files.newBufferedWriter(path)){
            String packageRegisterHeader = "#sender_nameSurname;sender_street;sender_zipCode;sender_town;sender_country;receiver_nameSurname;receiver_street;receiver_zipCode;receiver_town;receiver_country;sending_date;weight;description;price";
            stringBuilder.append(packageRegisterHeader).append("\n");
                for (Package p:packages.values())
                    stringBuilder.append(p.getFrom().getNameSurname()).append(";").append(p.getFrom().getAddressToFile()).append(";").append(p.getTo().getNameSurname()).append(";").append(p.getTo().getAddressToFile()).append(";").append(p.getSendingDate()).append(";").append(p.getWeight()).append(";").append(p.getDescription()).append(";").append(p.getPrice()).append("\n");
            bufferedWriter.write(stringBuilder.toString());
            packages.clear();
        }catch (IOException ioException){
            System.out.println("Something went wrong... " + Arrays.toString(ioException.getStackTrace()));
        }
    }

    /** Method lets specified user delete packages that have been sent by this user */
    @Override
    public void delete(User u) {
        for(Iterator<Package> iterator = packages.values().iterator(); iterator.hasNext(); ) {
            Package key = iterator.next();
            if(key.getFrom().equals(u)) {
                System.out.println("You sent this package:\n");
                System.out.println(key.get());
                    System.out.println("Do you want to delete it? If yes, press 'Y'.");
                    Scanner scanner = new Scanner(System.in);
                    String input = scanner.nextLine();
                    if (input.toUpperCase(Locale.ROOT).equals("Y")){
                        iterator.remove();
                        System.out.println("Package deleted successfully.");
                    }
            }
        }
    }

    /** Method lets specified user change packages' recipient or/and description */
    @Override
    public void change(User u) {
        for(Iterator<Package> iterator = packages.values().iterator(); iterator.hasNext(); ) {
            Package key = iterator.next();
            if(key.getFrom().equals(u)) {
                System.out.println("You sent this package:\n");
                System.out.println(key.get());
                System.out.println("Do you want to update it? If yes, press 'Y'.");
                Scanner scanner = new Scanner(System.in);
                String input = scanner.nextLine();
                if (input.toUpperCase(Locale.ROOT).equals("Y")){
                    System.out.println("Do you want to change package's recipient? If yes, press 'Y'.");
                     input = scanner.nextLine();
                    if (input.toUpperCase(Locale.ROOT).equals("Y")){
                        User user = getUser("I need some information about new recipient.");
                        key.setTo(user);
                    }
                    System.out.println("Do you want to change package's description? If yes, press 'Y'.");
                    input = scanner.nextLine();
                    if(input.toUpperCase(Locale.ROOT).equals("Y"))
                        key.scanDescription();

                System.out.println("Letter's information updated successfully:\n");
                System.out.println(key.get());
                }
            }
        }
    }
}
