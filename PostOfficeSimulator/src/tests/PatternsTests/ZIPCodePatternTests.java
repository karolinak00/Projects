package tests.PatternsTests;

import com.company.ZIPCodePattern;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

public class ZIPCodePatternTests {
    static ZIPCodePattern zipCodePattern;
    @BeforeAll
    static void initialize(){
        zipCodePattern = new ZIPCodePattern();
    }

    @Test
    void shouldReturnTrueIfZipCodeMatches(){
        Assertions.assertTrue(zipCodePattern.check("47-450"));
    }

    @Test
    void shouldReturnFalseIfZipCodeIsEmpty(){
        Assertions.assertFalse(zipCodePattern.check(""));
    }

    @Test
    void shouldReturnFalseIfZipCodeContainsLetters(){
        Assertions.assertFalse(zipCodePattern.check("4a-000"));
    }

    @Test
    void shouldReturnFalseIfZipCodeContainsWhiteChars(){
        Assertions.assertFalse(zipCodePattern.check("47 - 450"));
        Assertions.assertFalse(zipCodePattern.check("47-450\t"));
        Assertions.assertFalse(zipCodePattern.check("47-450\n"));
        Assertions.assertFalse(zipCodePattern.check(" 47-450"));
    }

    @Test
    void shouldReturnFalseIfZipCodeHasIncorrectFormat(){
        Assertions.assertFalse(zipCodePattern.check("470-50"));
        Assertions.assertFalse(zipCodePattern.check("4-45"));
        Assertions.assertFalse(zipCodePattern.check("4-450"));
        Assertions.assertFalse(zipCodePattern.check("47-45"));
        Assertions.assertFalse(zipCodePattern.check("47450"));
    }
}