package lab3;

public class EmployeeManager {
	public static void main(String[] args) {
		Employee James=new Employee("James Wright", 42,"Manager",20000);
		Employee Amy=new Employee("Amy Smith",27,"Design Coordinator",8000,15);
		Employee Peter=new Employee("Peter Coolidge",32,"Assistant Manager",12000,7);
		Employee John=new Employee("John Doe",22,"Engineer",10000,10);
	
		//다 추가한 후 출력
		System.out.println(James);
		System.out.println(Amy.toString());//toString은 적어도 안 적어도 둘 다 되는 것 같당 
		System.out.println(Peter.toString());
		System.out.println(John.toString());
		
		Employee new_face=new Employee("Jihyun Lee",21,"CEO",50000,30);
		System.out.println("새로운 "+new_face.getName()+"는 Amy와 같은 사람인가요? "+new_face.equals(Amy));
		
		James.vacation(10);
		Peter.vacation(10);
		
		System.out.println(James);
		System.out.println(Amy.toString());
		System.out.println(Peter.toString());
		System.out.println(John.toString());
	}
}
