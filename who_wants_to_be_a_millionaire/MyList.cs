using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace who_wants_to_be_a_millionaire
{
    class MyList
    {
        public List<Quiz> list = new List<Quiz>();

        // constructor & destructor
        public MyList() { }
        ~MyList()
        {
            delete_list();
        }

        // other methods
        public bool load_list(string path) // loads list from file
        {
            try
            {
                if (!File.Exists(path))
                    throw new Exception("Nie udalo sie znalezc pliku z quizem. Zostaniesz przeniesiony(a) do menu glownego.\n");
                else
                {
                    Quiz quiz = new Quiz();
                    StreamReader sr = File.OpenText(path);
                    string s = "";
                    int counter = 0;
                    while ((s = sr.ReadLine()) != null)
                    {
                        if (counter == 0)
                            quiz.set_question(s);

                        else if (counter == 1)
                            quiz.setA(s);

                        else if (counter == 2)
                            quiz.setB(s);

                        else if (counter == 3)
                            quiz.setC(s);

                        else if (counter == 4)
                            quiz.setD(s);

                        else if (counter == 5)
                            quiz.set_correct(s[0]);

                        if (counter < 6)
                            counter++;

                        if (counter == 6)
                        {
                            Quiz q = new Quiz(quiz);
                            add(q);
                            counter = 0;
                        }
                    }
                    sr.Close();
                    return true;
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("Cos poszlo nie tak. " + e.Message);
                return false;
            }
        }

        public void add(Quiz quiz)
        {
            list.Add(quiz);
        }

        public void delete_list()
        {
            list.Clear();
        }

        public bool ask(ref Player player, ref int counter, ref bool _telephone, ref bool _audience, ref bool __50_50)
        {
            Random random = new Random();
            char answer = ' ';
            bool tmp = true;
            Console.Clear();
            if (player.get_score().get_score() == 0)
                Console.WriteLine("Pierwsze pytanie:\n");
            else if (player.get_score().get_score() > 0 && player.get_score().get_score() < 11)
            {

                int rand = random.Next(1, 4);

                if (rand == 1)
                    Console.WriteLine("Kolejne pytanie:\n");
                else if (rand == 2)
                    Console.WriteLine("Ciekawe, czy znasz odpowiedz na to pytanie:\n");
                else
                    Console.WriteLine("Poznajmy tresc nastepnego pytania:\n");
            }

            if (player.get_score().get_score() == 11)
                Console.WriteLine("Jestes juz krok od wygranej. Przed Toba ostatnie pytanie:\n");

            Console.WriteLine("{0}\n{1}\n{2}\n{3}\n{4}\n", list[counter].get_question(), list[counter].getA(), list[counter].getB(), list[counter].getC(), list[counter].getD());

            Console.WriteLine("Jesli chcesz uzyc kola ratunkowego, wybierz listere 'k'.\n");


            do
            {
                bool correct_option = false;
                do
                {
                    Console.WriteLine("Twoja odpowiedz: ");
                    var input = Console.ReadLine();
                    if (string.IsNullOrEmpty(input))
                    {
                        Console.WriteLine("Podaj opcje!");
                        Console.WriteLine("Wcisnij dowolny klawisz aby kontynuowac.");
                        Console.ReadKey();
                        Console.Clear();
                    }
                    else
                    {
                        answer = input[0];
                        correct_option = true;
                    }
                } while (!correct_option);



                if (answer == 'k')
                {
                    char choice;
                    string input2;
                    do
                    {
                        Console.WriteLine("Aby zadzwonic do eksperta, wybierz 1.");
                        Console.WriteLine("Aby pomogla Ci publicznosc, wybierz 2.");
                        Console.WriteLine("Aby odrzucic dwie bledne odpowiedzi, wybierz 3.");
                        Console.WriteLine("Jesli nie chcesz uzyc kola ratunkowego, wybierz znak rozny od {1, 2, 3}.\n");
                        Console.WriteLine();
                        input2 = Console.ReadLine();
                        if (string.IsNullOrEmpty(input2))
                        {
                            Console.WriteLine("Podaj opcje!");
                            Console.WriteLine("Wcisnij dowolny klawisz aby kontynuowac.");
                            Console.ReadKey();
                            Console.Clear();
                        }
                    } while (string.IsNullOrEmpty(input2));
                    choice = input2[0];

                    if (choice == '1' || choice == '2' || choice == '3')
                    {
                        if (choice == '1')
                        {
                            if (_telephone)
                            {
                                _telephone = false;
                                Telephone t = new Telephone();
                                t.help(list[counter].get_correct(), list[counter].get_question(), list[counter].getA(), list[counter].getB(), list[counter].getC(), list[counter].getD());
                            }
                            else
                            {
                                Console.WriteLine("To kolo ratunkowe zostalo juz wykorzystane.\n");
                                Console.WriteLine("Wcisnij dowolny klawisz aby kontynuowac.");
                                Console.ReadKey();
                                Console.Clear();
                            }
                        }
                        else if (choice == '2')
                        {
                            if (_audience)
                            {
                                _audience = false;
                                Audience a = new Audience();
                                a.help(list[counter].get_correct());
                            }
                            else
                            {
                                Console.WriteLine("To kolo ratunkowe zostalo juz wykorzystane.\n");
                                Console.WriteLine("Wcisnij dowolny klawisz aby kontynuowac.");
                                Console.ReadKey();
                                Console.Clear();
                            }
                        }
                        else if (choice == '3')
                        {
                            if (__50_50)
                            {
                                __50_50 = false;
                                Fifty_fifty f = new Fifty_fifty();
                                f.help(list[counter].get_correct());
                            }
                            else
                            {
                                Console.WriteLine("To kolo ratunkowe zostalo juz wykorzystane.\n");
                                Console.WriteLine("Wcisnij dowolny klawisz aby kontynuowac.");
                                Console.ReadKey();
                                Console.Clear();
                            }
                        }

                    }
                }
                else if (Char.ToUpper(answer) < 'A' || Char.ToUpper(answer) > 'D')
                    Console.WriteLine("Podaj poprawny wariant!\n");
                else
                    tmp = false;
            } while (tmp);

            if (Char.ToUpper(answer) == list[counter].get_correct())
            {
                int rand = random.Next(1, 4);

                if (rand == 1)
                    Console.WriteLine("Znakomicie!\n");
                else if (rand == 2)
                    Console.WriteLine("Wow, posiadasz niesamowita wiedze!\n");
                else
                    Console.WriteLine("To jest poprawna odpowiedz!\n");

                return true;
            }

            else
            {
                Console.WriteLine("Niestety, podana przez Ciebie odpowiedz jest bledna. Prawidlowa odpowiedz to odpowiedz " + list[counter].get_correct() + ".\n");
                Console.WriteLine("To kolo ratunkowe zostalo juz wykorzystane.\n");
                Console.WriteLine("Wcisnij dowolny klawisz aby kontynuowac.");
                Console.ReadKey();
                return false;
            }
        }
    }
}
