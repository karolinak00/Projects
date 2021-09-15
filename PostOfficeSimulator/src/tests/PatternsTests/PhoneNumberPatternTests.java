package tests.PatternsTests;


import com.company.PhoneNumberPattern;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

public class PhoneNumberPatternTests {

    static PhoneNumberPattern phoneNumberPattern;

    @BeforeAll
    static void initialize(){
       phoneNumberPattern = new PhoneNumberPattern();
    }

    @Test
    void shouldReturnTrueIfPhoneNumberMatches(){
        Assertions.assertTrue(phoneNumberPattern.check("165423817"));
    }

    @Test
    void shouldReturnFalseIfPhoneNumberIsTooShort(){
        Assertions.assertFalse(phoneNumberPattern.check("19643827"));
    }

    @Test
    void shouldReturnFalseIfPhoneNumberIsTooLong(){
        Assertions.assertFalse(phoneNumberPattern.check("1964382790"));
    }

    @Test
    void shouldReturnFalseIfPhoneNumberIsEmpty(){
        Assertions.assertFalse(phoneNumberPattern.check(""));
    }

    @Test
    void shouldReturnFalseIfPhoneNumberContainsLetters(){
        Assertions.assertFalse(phoneNumberPattern.check("19a382790"));
    }

    @Test
    void shouldReturnFalseIfPhoneNumberContainsWhiteChars(){
        Assertions.assertFalse(phoneNumberPattern.check("19382790\n"));
    }
}
