package LAB8Super;

public class EmployeeSuper extends personSuper {
    private String Department, Designation;
    EmployeeSuper(){}
    EmployeeSuper(String name, int age, String address,String Department, String Designation)
    {
        super(name, age, address);
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
    @Override
    public String toString() {
        return super.toString()+"\nDepartment: "+getDepartment()+"\nDesignation: "+getDesignation();
    }

}
