using System;
using MemoryLeaker.LeakerLibrary;

namespace MemoryLeaker
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine("Press enter key to start leaking");
            Console.ReadLine();
            for (var i = 0; i < 5000; i++)
            {
                var dummy = LeakyClient.Create<IDummy>();
                //do something with the dummy
            }
            Console.WriteLine("Leaking done!");
            Console.ReadLine();
        }
    }
}
