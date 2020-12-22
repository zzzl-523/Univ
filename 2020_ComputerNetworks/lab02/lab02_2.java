package lab02_2;

import java.util.Scanner;

public class lab02_2 {
	private static String makeOrdinalNumber(int num) {
		if((num%100)/10==1) {	//11,12,13,111,112,113 ���� �̸� ó��
			return num+"th";
		}
		
		switch(num%10) {
			case 1:
				return num+"st";
			case 2:
				return num+"nd";
			case 3:
				return num+"rd";
		}
		
		return num+"th";
	}
	
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		String score = scan.nextLine().toUpperCase(); //�ϴ� line���� �ް� split�ؼ� ���� �����ش�
		String[] scoreList=score.split(" ");
		float howMany=scoreList.length;
		float totalScore=0;
		
		for(int i=1;i<=howMany;i++) {
			switch(scoreList[i-1]) {
				case "A":
					System.out.println(makeOrdinalNumber(i)+" student's score is"+100);
					totalScore+=100;
					break;
				case "B":
					System.out.println(makeOrdinalNumber(i)+" student's score is"+90);
					totalScore+=90;
					break;
				case "C":
					System.out.println(makeOrdinalNumber(i)+" student's score is"+80);
					totalScore+=80;
					break;
				case "D":
					System.out.println(makeOrdinalNumber(i)+" student's score is"+70);
					totalScore+=70;
					break;
				case "F":
					System.out.println(makeOrdinalNumber(i)+" student's score is"+0);
					break;
				}
		}
		//System.out.printf("This class's average = %.2f\n",(totalScore/howMany));	
		//float�� ����Ϸ��� type casting ����� �Ѵ�.
		//float/float ���� �� ����� ���ȴ�.
		
		String fixedNum=String.format("%.2f", totalScore/howMany);	//���� �����ֱ�
		System.out.println("This class's average ="+fixedNum);
	}
	
}
