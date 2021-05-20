using System;
using System.Collections.Generic;
using System.Text;

namespace who_wants_to_be_a_millionaire
{
    class Telephone
    {
        public Telephone() { }
        ~Telephone() { }

        public void help(char correct, string question, string A, string B, string C, string D)
        {
            Console.WriteLine("-Halo?");
            Console.WriteLine("-Witaj Maurycy, nasz ekspercie. Potrzebujemy Twojej pomocy.");
            Console.WriteLine("-Z przyjemnoscia pomoge. Jak brzmi pytanie?");
            Console.WriteLine("-" + question + "\n" + A + "\n" + B + "\n" + C + "\n" + D + "\n");

            Random random = new Random();
            int rand = random.Next(1, 4);

            if (rand == 1)
                Console.WriteLine("-To na pewno odpowiedz " + correct + ".");
            else if (rand == 2)
                Console.WriteLine("-Nie jestem specjalista w tej dziedzinie, ale wydaje mi sie, ze poprawna odpowiedz to " + correct + ".");
            else
                Console.WriteLine("-Ostatnio szukalem odpowiedzi na to pytanie w internecie. Poprawna odpowiedz to " + correct + ".");
            Console.WriteLine("-Dziekuje za odpowiedz. Do uslyszenia w kolejnej grze!");
            Console.WriteLine("-Cala przyjemnosc po mojej stronie. Do uslyszenia!\n");
        }
    }
}
