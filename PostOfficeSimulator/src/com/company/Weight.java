package com.company;

import java.util.Scanner;

public class Weight {
    private double weight;

    // constructors:
    public Weight(){
        scan();
    }

    public Weight(double weight){
        setWeight(weight);
    }

    // getter:
    public double getWeight(){
        return this.weight;
    }

    // setter:
    private void setWeight(double weight){
        this.weight = weight;
    }


    // other methods:
    /** Method gets information from user */
    public void scan(){
        Scanner scanner = new Scanner(System.in);
        double tmp;
        boolean correct = false;
        do{
            System.out.println("Enter package's weight: ");
            tmp = scanner.nextDouble();
            if(correctWeight(tmp)){
                setWeight(tmp);
                correct = true;
            }
        }while(!correct);
    }

    /** Method checks if weight provided by the user is correct */
    public boolean correctWeight(double w){
        if(w <= 0){
            System.out.println("Weight must be greater than 0!");
            return false;
        }
        else if(w > 20){
            System.out.println("Package that You want to send is too heavy. I can't send packages which weight is greater than 20kg.");
            return false;
        }
        else
            return true;
    }
}
