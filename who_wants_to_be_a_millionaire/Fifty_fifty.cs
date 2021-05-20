using System;
using System.Collections.Generic;
using System.Text;

namespace who_wants_to_be_a_millionaire
{
    class Fifty_fifty : Lifeline
    {
        public Fifty_fifty() { }
        ~Fifty_fifty() { }

        public void help(char correct)
        {
            Random random = new Random();
            int rand = random.Next(0, 4);
            char incorrect = ' '; // wrong answer
            if (correct == 'A')
            {
                if (rand == 1)
                    incorrect = 'C';
                else if (rand == 2)
                    incorrect = 'D';
                else
                    incorrect = 'B';
            }
            else if (correct == 'B')
            {
                if (rand == 1)
                    incorrect = 'A';
                else if (rand == 2)
                    incorrect = 'C';
                else
                    incorrect = 'D';
            }
            else if (correct == 'C')
            {
                if (rand == 1)
                    incorrect = 'A';
                else if (rand == 2)
                    incorrect = 'B';
                else
                    incorrect = 'D';
            }
            else if (correct == 'D')
            {
                if (rand == 1)
                    incorrect = 'B';
                else if (rand == 2)
                    incorrect = 'C';
                else
                    incorrect = 'A';
            }

            if (random.Next(0, 101)%2 == 1)
                Console.WriteLine("Poprawna odpowiedz to {0} lub {1}", correct, incorrect);
            else
                Console.WriteLine("Poprawna odpowiedz to {0} lub {1}", incorrect, correct);
        }
    }
}
