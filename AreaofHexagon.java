import java.util.Scanner;
public class AreaofHexagon {

        public static void main(String[] args)
        {
            System.out.print("Enter the length of the side of hexagon: ");
            Scanner sc = new Scanner(System.in);
    
            double side = sc.nextDouble();
    
            if(side<0)
            {
                System.out.println("The area can not be computed due to invalid side length.");
            }
            else
            {
                double area = (6*Math.pow(side, 2))/(4*Math.tan(0.523599));
    
                System.out.print("Area of the Hexagon: "+area);
            }
        }
    
    
    
}
