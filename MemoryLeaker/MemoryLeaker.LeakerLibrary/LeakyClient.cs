namespace MemoryLeaker.LeakerLibrary
{
    public class LeakyClient
    {
        public static T Create<T>()
        {
            return ClassBuilder.Instance.CreateImplementation<T>();
        }
    }
}
