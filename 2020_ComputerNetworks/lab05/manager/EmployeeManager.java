package kr.co.lab05.manager;

import kr.co.lab05.employee.*;

import java.time.*;
import java.util.Random;

public class EmployeeManager {
	public static void main(String[] args) {
		Random rnd = new Random();
		rnd.setSeed(System.currentTimeMillis());
		
		Employee worker = new Employee("Lee", 4500);
		LocalDate mydate = LocalDate.of(2020, 4, 16);
		System.out.println("����� : " + mydate);
		System.out.println(worker);
		int incentive_Month = rnd.nextInt(12)+1;	//0~11 + 1
		
		int M_count = 0;
		int Y_count = 1;
		while(worker.getBalance() < 20000) {
			worker.receiveSalary();
		
			if(M_count == incentive_Month) {
				worker.receiveSalary();	//�� �� ������ 100%
				System.out.println(Y_count + "���� " + M_count + "���� �μ�Ƽ�긦 �޾ҽ��ϴ�");
			}
			if(M_count == 12) {
				Y_count++;
				M_count=0;
				int howMuch = rnd.nextInt(11);
				worker.increaseYearlySalary(howMuch);
				System.out.println(Y_count + "���� ������ " + howMuch + "% �λ�Ǿ����ϴ�.");
				incentive_Month = rnd.nextInt(12) + 1;
			}
			
			M_count++;
		}
		
		if(worker.getBalance() >= 20000) {
			LocalDate finaldate = LocalDate.of(2020+Y_count, M_count, 16);
			System.out.println("��¥ : " + finaldate);
		}
		System.out.println(worker);
	}
}

