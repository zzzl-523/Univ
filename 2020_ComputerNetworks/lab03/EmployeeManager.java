package lab3;

public class EmployeeManager {
	public static void main(String[] args) {
		Employee James=new Employee("James Wright", 42,"Manager",20000);
		Employee Amy=new Employee("Amy Smith",27,"Design Coordinator",8000,15);
		Employee Peter=new Employee("Peter Coolidge",32,"Assistant Manager",12000,7);
		Employee John=new Employee("John Doe",22,"Engineer",10000,10);
	
		//�� �߰��� �� ���
		System.out.println(James);
		System.out.println(Amy.toString());//toString�� ��� �� ��� �� �� �Ǵ� �� ���� 
		System.out.println(Peter.toString());
		System.out.println(John.toString());
		
		Employee new_face=new Employee("Jihyun Lee",21,"CEO",50000,30);
		System.out.println("���ο� "+new_face.getName()+"�� Amy�� ���� ����ΰ���? "+new_face.equals(Amy));
		
		James.vacation(10);
		Peter.vacation(10);
		
		System.out.println(James);
		System.out.println(Amy.toString());
		System.out.println(Peter.toString());
		System.out.println(John.toString());
	}
}
