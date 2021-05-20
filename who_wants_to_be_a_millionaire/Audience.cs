using System;
using System.Collections.Generic;
using System.Text;

namespace who_wants_to_be_a_millionaire
{
    class Audience
    {
        public Audience() { }

        ~Audience() { }

        public void help(char correct)
        {
            double a = 0, b = 0, c = 0, d = 0;
            Random random = new Random();

            if (correct == 'A')
            {
                a = 37.0 + random.Next(0, 64);
                b = (100 - a) / 3.0;
                c = (100 - a - b) / 4.0;
                d = 100.0 - a - b - c;
            }
            else if (correct == 'B')
            {
                b = 37.0 + random.Next(0, 64);
                d = (100 - b) / 5.0;
                a = (100 - b - d) / 9.0;
                c = 100.0 - b - d - a;
            }
            else if (correct == 'C')
            {
                c = 37.0 + random.Next(0, 64);
                b = (100 - c) / 8.0;
                d = (100 - c - b) / 16.0;
                a = 100.0 - c - b - d;
            }
            else if (correct == 'D')
            {
                d = 37.0 + random.Next(0, 64);
                c = (100 - d) / 2.0;
                a = (100 - d - c) / 3.0;
                b = 100.0 - d - c - a;
            }

            Console.WriteLine("Prosimy o pomoc publicznosc. Maja Panstwo 5 sekund na oddanie glosu.\n");
            Console.WriteLine("Wcisnij dowolny klawisz aby kontynuowac.");
            Console.ReadKey();
            Console.Clear();
            Console.WriteLine("Oto wyniki glosowania:");
            Console.WriteLine("A: " + a + "%.");
            Console.WriteLine("B: " + b + "%.");
            Console.WriteLine("C: " + c + "%.");
            Console.WriteLine("D: " + d + "%.\n");
            Console.WriteLine("Dziekujemy za pomoc.\n");
        }
    }
}
