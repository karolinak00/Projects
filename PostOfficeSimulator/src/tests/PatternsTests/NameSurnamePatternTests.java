package tests.PatternsTests;

import com.company.NameSurnamePattern;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

public class NameSurnamePatternTests {
    static NameSurnamePattern nameSurnamePatternPattern;
    @BeforeAll
    static void initialize(){nameSurnamePatternPattern = new NameSurnamePattern();
    }

    @Test
    void shouldReturnTrueIfStringMatches(){

        Assertions.assertTrue(nameSurnamePatternPattern.check("Jan Kowalski"));
        Assertions.assertTrue(nameSurnamePatternPattern.check("Ilona Kowalska-Nowak"));
    }

    @Test
    void shouldReturnFalseIfStringIsEmpty(){
        Assertions.assertFalse(nameSurnamePatternPattern.check(""));
    }

    @Test
    void shouldReturnFalseIfStringContainsNumbers(){
        Assertions.assertFalse(nameSurnamePatternPattern.check("Jan3k Kow1lski"));
    }

    @Test
    void shouldReturnFalseIfStringDoesNotMatchToPattern(){
        Assertions.assertFalse(nameSurnamePatternPattern.check("J K"));
        Assertions.assertFalse(nameSurnamePatternPattern.check("JaN Ko"));
        Assertions.assertFalse(nameSurnamePatternPattern.check("jan kowalski"));
        Assertions.assertFalse(nameSurnamePatternPattern.check("Jan"));
        Assertions.assertFalse(nameSurnamePatternPattern.check("Ilona Kowalska-Nowak-Nowicka"));
    }
}
