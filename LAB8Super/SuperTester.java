package LAB8Super;

public class SuperTester {
    public static void main(String[] args) {
        System.out.println("Part Time Employee: \n");
        PartTimeEmployeeSuper P1 = new PartTimeEmployeeSuper("Xavier Rolex",22,"Mirpur","Cse","CEO",10,100);
        System.out.println(P1.toString());
        System.out.println("....................");
    
        System.out.println();
        System.out.println("Full Time Employee: \n");
        FullTimeEmployeeSuper F1 = new FullTimeEmployeeSuper("Nafis Anzum",30,"Mirpur","BBA","TA",15000,25);
        System.out.println(F1.toString());
        System.out.println("....................");
}
}
