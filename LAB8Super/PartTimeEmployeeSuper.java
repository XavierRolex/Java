package LAB8Super;

public class PartTimeEmployeeSuper extends EmployeeSuper {
    private double hours, rate;
    PartTimeEmployeeSuper(){}
    PartTimeEmployeeSuper(String name, int age, String address,String Department, String Designation,double hours, double rate)
    {
        super(name, age, address, Department, Designation);
        this.hours= hours;
        this.rate= rate;
    }
    public double getHours() {
        return hours;
    }
    public void setHours(double hours) {
        this.hours = hours;
    }
    public double getRate() {
        return rate;
    }
    public void setRate(double rate) {
        this.rate = rate;
    }
    public double salary(){
        double salary = hours*rate;
        return salary;

    }
    @Override
    public String toString() {
        
        return super.toString()+ "\nSalary: "+salary();
    }
}