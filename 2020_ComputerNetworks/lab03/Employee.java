package lab3;

public class Employee {
	private String name;
	private	int age;
	private	String position;
	private	int salary;
	private	int vacationDays;
	
	public	Employee(String name, int age){//생성자
		setName(name);
		setAge(age);
		position="Employee";
		salary=5000;
		vacationDays=20;
	}
	public Employee(String name, int age, String position, int salary){
		setName(name);
		setAge(age);
		setPosition(position);
		setSalary(salary);
		vacationDays=20;
	}
	public Employee(String name, int age, String position, int salary, int vacationDays){
		setName(name);
		setAge(age);
		setPosition(position);
		setSalary(salary);
		setVacationDays(vacationDays);
	}
	
	public String getName() {
		return name;
	}
	public int getAge() {
		return age;
	}
	public String getPosition() {
		return position;
	}
	public int getSalary() {
		return salary;
	}
	public int getVacationDays() {
		return vacationDays;
	}
	
	
	public void setName(String name) {
		this.name=name;
	}
	public void setAge(int age) {
		this.age=age;
	}
	public void setPosition(String position) {
		this.position=position;
	}
	public void setSalary(int salary) {
		this.salary=salary;
	}
	public void setVacationDays(int vacation) {
		this.vacationDays=vacation;
	}
	
	
	public boolean equals(Employee anotherEmp) {
		if(this.name.equals(anotherEmp.name)&&this.age==anotherEmp.age&&this.position.equals(anotherEmp.name)){
			return true;
		}
		else return false;
	}
	public String toString() {
		return "Name: "+this.name+", Age: "+this.age+", Position: "+this.position+", Salary: "+this.salary+", VacationDays: "+this.vacationDays;
	}
	public boolean vacation(int gagosipa) {
		if(gagosipa>this.vacationDays) {
			System.out.println("남은 휴가일수가 부족합니다.");
			return false;
		}
		else {
			vacationDays-=gagosipa;
			System.out.printf("휴가를 사용하였습니다. 남은 휴가일수 : %d\n",vacationDays);
			return true;
		}
	}
}
