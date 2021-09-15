package tests.PatternsTests;

import com.company.CountryPattern;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

public class CountryPatternTests {
    static CountryPattern countryPattern;
    @BeforeAll
    static void initialize(){
        countryPattern = new CountryPattern();
    }

    @Test
    void shouldReturnTrueIfStringMatches(){
        Assertions.assertTrue(countryPattern.check("Poland"));
        Assertions.assertTrue(countryPattern.check("United States of America"));
        Assertions.assertTrue(countryPattern.check("Czech Republic"));
    }

    @Test
    void shouldReturnFalseIfStringIsEmpty(){
        Assertions.assertFalse(countryPattern.check(""));
    }

    @Test
    void shouldReturnFalseIfStringContainsNumbers(){
        Assertions.assertFalse(countryPattern.check("Pol1nd"));
    }

    @Test
    void shouldReturnFalseIfStringDoesNotMatchToPattern(){
        Assertions.assertFalse(countryPattern.check("U S A"));
        Assertions.assertFalse(countryPattern.check("poland"));
        Assertions.assertFalse(countryPattern.check("POlanD"));
    }
}
