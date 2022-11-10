package Lab8;

public class partTimeEmployee extends Employee{
    private double hours, rate;
    partTimeEmployee(){}
    partTimeEmployee(double hours, double rate)
    {
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
        return "Part-time Employee"+"\n\nName: "+getName()+"\nAge: "+getAge()+"\nAddress: "+getAddress()+"\nDepartment: "+getDepartment()+"\nDesignation: "+getDesignation();
    }

    
    

}
