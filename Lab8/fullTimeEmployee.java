package Lab8;
public class fullTimeEmployee extends Employee {
    private double basic, allowance;
    fullTimeEmployee(){}
    
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

    public String toString() {
        return "Full-Time Employee"+"\n\nName: "+getName()+"\nAge: "+getAge()+"\nAddress: "+getAddress()+"\nDepartment: "+getDepartment()+"\nDesignation: "+getDesignation();
    }
    public double salary(){
        double salary = (basic+((allowance/100)*basic));
        return salary;
    }


}

