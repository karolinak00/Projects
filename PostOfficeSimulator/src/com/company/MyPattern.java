package com.company;

public class MyPattern {
    private String pattern;

    public MyPattern(){}

    protected void setPattern(String pattern){
        this.pattern = pattern;
    }

    public boolean check(String string){
        return string.matches(pattern);
    }
}