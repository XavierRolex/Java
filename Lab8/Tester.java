package Lab8;

import java.util.Scanner;

public class Tester {
    public static void main(String[] args) {
        
        try (Scanner input = new Scanner(System.in)) {

            while (true)
            {  
            System.out.println("Are you a part time Employee: ");
            String choice = input.next();
            if (choice.equals("yes")||choice.equals("Yes")||choice.equals("YES"))
            {
            
            parttime();
            
            }
            else 
            {
                System.out.println("Are you a Full Time employee: ");
                choice=input.next();

                if (choice.equals("yes")||choice.equals("Yes")||choice.equals("YES"))
               {
                fulltime(); //calling the fulltime method.          
               }
               else 
               {
                System.out.println("Get a job first!");
                break;
               }
            }
            
            }
        }
       
        
        
    }
    public static void parttime() {
        partTimeEmployee p1 = new partTimeEmployee();
        Scanner input = new Scanner(System.in);
        System.out.print("Enter your name: ");
            p1.setName(input.nextLine());
            System.out.print("Enter your Department: ");
            p1.setDepartment(input.nextLine());
            System.out.print("Enter your address: ");
            p1.setAddress(input.nextLine());
            System.out.print("Enter your age: ");
            p1.setAge(input.nextInt());
            input.nextLine();
            System.out.print("Enter your Designation: ");
            p1.setDesignation(input.nextLine());
            System.out.println("");
            System.out.print("Enter your Rate: ");
            p1.setRate(input.nextDouble()); 
            System.out.print("Enter your hours:");
            p1.setHours(input.nextDouble());
            System.out.println("");
            System.out.println(p1.toString());
            System.out.println("Your Salary is "+p1.salary()+ "Tk");
            System.out.println("-----------------------");
            System.out.println();        
    }
    public static void fulltime() {
        fullTimeEmployee f1 = new fullTimeEmployee();
        Scanner input = new Scanner(System.in);
        System.out.print("Enter your name: ");
            f1.setName(input.nextLine());
            System.out.print("Enter your address: ");
            f1.setAddress(input.nextLine());
            System.out.print("Enter your age: ");
            f1.setAge(input.nextInt());
            input.nextLine();
            System.out.print("Enter your Department: ");
            f1.setDepartment(input.nextLine());
            System.out.print("Enter your Designation: ");
            f1.setDesignation(input.nextLine());
            System.out.println("");
            System.out.print("Enter your Basic: ");
            f1.setBasic(input.nextDouble()); 
            System.out.print("Enter your Allowance: ");
            f1.setAllowance(input.nextDouble());
            System.out.println("");
            System.out.println(f1.toString());
            System.out.println("Your Salary is "+f1.salary()+ "Tk");
            System.out.println("-----------------------");
            System.out.println();
    }
    
    
}

