package Lab8;

public class Employee extends person{
    private String Department, Designation;
    Employee(){}
    Employee(String Department, String Designation)
    {
        this.Department=Department;
        this.Designation=Designation;
    }
    public String getDepartment() {
        return Department;
    }
    public void setDepartment(String department) {
        Department = department;
    }
    public String getDesignation() {
        return Designation;
    }
    public void setDesignation(String designation) {
        Designation = designation;
    }
    
    
    
}
