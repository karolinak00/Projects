using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace who_wants_to_be_a_millionaire
{
    class Stats
    {
        public LinkedList<Player> stats = new LinkedList<Player>();
        public Stats() { }
        ~Stats()
        {
            delete_stats();
        }

        public bool create_stats()
        {
            try
            {
                if (!File.Exists(@"C:\Users\karol\source\repos\Projects\who_wants_to_be_a_millionaire\statistics.txt"))
                    throw new Exception("Nie udalo sie znalezc pliku ze statystykami. Program zakonczy swoje dzialanie.\n");
                else
                {
                    Player player = new Player();
                    StreamReader sr = File.OpenText(@"C:\Users\karol\source\repos\Projects\who_wants_to_be_a_millionaire\statistics.txt");
                    string s = "";
                    int counter = 0;
                    while ((s = sr.ReadLine()) != null)
                    {
                        if (counter == 0)
                            player.set_name(s);

                        else if (counter == 1)
                            player.set_surname(s);

                        else if (counter == 2)
                        {
                            Int32.TryParse(s, out int score);
                            player.set_score(score);
                        }


                        if (counter < 3)
                            counter++;

                        if (counter == 3)
                        {
                            Player p = new Player(player);
                            add(ref p);
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

        public void add(ref Player player)
        {
            stats.AddLast(player);
        }

        public void print_stats()
        {
            foreach (var p in stats)
            {
                Console.WriteLine(p.get_name() + " " + p.get_surname() + " " + p.get_score().get_score());
            }
        }

        public void delete_stats()
        {
            stats.Clear();
        }

        public void save_stats()
        {
            if (!File.Exists(@"C:\Users\karol\source\repos\Projects\who_wants_to_be_a_millionaire\statistics.txt"))
            {
                Console.WriteLine("Nie udalo sie otworzyc pliku ze statystykami, dlatego statystyki nie zostana zapisane.\n");
                Console.WriteLine("Wcisnij dowolny klawisz aby kontynuowac.");
                Console.ReadKey();
                Console.Clear();
            }
            else
            {
                StreamWriter sw = new StreamWriter(@"C:\Users\karol\source\repos\Projects\who_wants_to_be_a_millionaire\statistics.txt", false);
                foreach (Player player in stats)
                {
                    sw.WriteLine("{0}\n{1}\n{2}", player.get_name(), player.get_surname(), player.get_score().get_score());
                }
                sw.Close();

            }
        }
    }
}
