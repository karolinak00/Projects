package tests.PatternsTests;

import com.company.StreetPattern;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

public class StreetPatternTests {
    static StreetPattern streetPattern;
    @BeforeAll
    static void initialize(){
        streetPattern = new StreetPattern();
    }

    @Test
    void shouldReturnTrueIfStreetMatches(){
        Assertions.assertTrue(streetPattern.check("Moniuszki 79"));
        Assertions.assertTrue(streetPattern.check("3 maja 12/89"));
        Assertions.assertTrue(streetPattern.check("Henryka VIII 27a/10"));
        Assertions.assertTrue(streetPattern.check("Krakowska 278B/10"));
    }

    @Test
    void shouldReturnFalseIfStreetIsEmpty(){
        Assertions.assertFalse(streetPattern.check(""));
    }

    @Test
    void shouldReturnFalseIfStreetDoesNotContainNumber(){
        Assertions.assertFalse(streetPattern.check("Warszawska"));
    }
}
