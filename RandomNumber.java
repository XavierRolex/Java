public class RandomNumber
{
    public static void main(String[] args)
    {
        int min = 1;
        int max = 1000;

        int randNum1 = (int)(min + Math.random()*(max-min+1));
        int randNum2 = (int)(min + Math.random()*(max-min+1));

        System.out.println("First Random Number: "+randNum1);
        System.out.println("First Random Number: "+randNum2);

        if(randNum1>randNum2)
        {
            int temp = randNum1-1;

            while(temp>=randNum2+1)
            {
                if(temp%5==0 || temp%8==0)
                {
                    System.out.print(temp+ " ");
                }
                temp--;
            }
        }
        else
        {
            int temp = randNum2-1;

            while(temp>=randNum1+1)
            {
                if(temp%5==0 || temp%8==0)
                {
                    System.out.print(temp+ " ");
                }
                temp--;
            }
        }
    }
}
