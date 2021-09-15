package tests.PatternsTests;

import com.company.MessagePattern;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

public class MessagePatternTests {
    static MessagePattern messagePattern;
    static StringBuilder sb;

    @BeforeAll
    static void initialize(){
        messagePattern = new MessagePattern();
        sb = new StringBuilder();
        for(int i=0; i<50; i++)
            sb.append((char) (((int)(Math.random() * 94)) + (int)' '));
    }

    @Test
    void shouldReturnTrueIfMessageMatches(){
        Assertions.assertTrue(messagePattern.check(sb.toString()));
        Assertions.assertTrue(messagePattern.check(sb.toString() + " ")); // exactly 50 characters
    }

    @Test
    void shouldReturnFalseIfMessageIsEmpty(){
        Assertions.assertFalse(messagePattern.check(""));
    }

    @Test
    void shouldReturnFalseIfMessageIsTooLong(){
        Assertions.assertFalse(messagePattern.check(sb.toString() + "ab")); // more than 50 characters
    }
}