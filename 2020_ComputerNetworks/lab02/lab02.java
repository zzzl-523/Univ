package lab2;

import java.util.Scanner;

public class lab02 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String input = scan.nextLine(); //문장으로 받을거니까 nextLine()
		
		String[] peopleInfo=input.split(",");
		String[] nameList=peopleInfo[0].split(" ");
		int nameLength = nameList.length;
		
		String name1=nameList[1].substring(0,1).toUpperCase();
		String name2=nameList[2].substring(0,1).toUpperCase();
		String name_Last=nameList[0].substring(0,1).toUpperCase();
		
		peopleInfo[1] = peopleInfo[1].replace("homework","Homework");
		peopleInfo[1] = peopleInfo[1].replace("ppt","pdf");
		
		System.out.println("Name Length(Korean) : "+nameLength);
		System.out.println(name1+"."+name2+"."+name_Last+nameList[0].substring(1)+" submitted"+peopleInfo[1]);
		
	}
}
