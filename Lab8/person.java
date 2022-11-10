package Lab8;

public class person {
    private String name, address;
    private int age;
    person(){}
    person (String name, int age, String address){
        this.name= name;
        this.age= age;
        this.address= address;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getAddress() {
        return address;
    }
    public void setAddress(String address) {
        this.address = address;
    }
    public int getAge() {
        return age;
    }
    public void setAge(int age) {
        this.age = age;
    }
    

    
}
