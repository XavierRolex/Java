package LAB8Super;

public class FullTimeEmployeeSuper extends EmployeeSuper {
    private double basic, allowance;
    FullTimeEmployeeSuper(){}
    FullTimeEmployeeSuper(String name, int age, String address,String Department, String Designation,double basic, double allowance)
    {
        super(name, age, address, Department, Designation);
        this.basic= basic;
        this.allowance= allowance;
    }
    public double getBasic() {
        return basic;
    }
    public void setBasic(double basic) {
        this.basic = basic;
    }
    public double getAllowance() {
        return allowance;
    }
    public void setAllowance(double allowance) {
        this.allowance = allowance;
    }
    public double salary(){
        double salary = (basic+((allowance/100)*basic));
        return salary;
    }
    @Override
    public String toString() {
        
        return super.toString()+ "\nSalary: "+salary();
    }
}
