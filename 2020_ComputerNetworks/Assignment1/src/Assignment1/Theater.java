package Assignment1;

import java.util.Scanner;

public class Theater {
	
	public static void main(String[] args) {
		int A_menu;
		String A_login_id, A_login_pw;
		String A_ID, A_PW;
		boolean correct = false;
		User[] userList = new User[50];
		int memberCount = 0;
		int B_menu;
		Movie[] movieList = new Movie[9];
		int B_buyTicketMenu, B_chooseMovie;
		String B_chooseSeat;
		int ticketNum = 0;

		
		//��ȭ ��� �����
		movieList[1] = new Movie("�����", 0, 3);
		movieList[2] = new Movie("����", 3, 6);
		movieList[3] = new Movie("�ظ�����", 6, 9);
		movieList[4] = new Movie("��󷣵�", 9, 12);
		movieList[5] = new Movie("�ܿ�ձ�", 12, 15);
		movieList[6] = new Movie("��Ž�� �ڳ�", 15, 18);
		movieList[7] = new Movie("�����", 18, 21);
		movieList[8] = new Movie("��������", 21, 24);
		
		
		Scanner scan = new Scanner(System.in);
		while(true) {
			System.out.println("*******��ȭ ���� ���α׷�*******");
			System.out.println("1. �α���\n2. ȸ������\n3. ����");
			System.out.print("�޴��� �������ּ��� : ");
			A_menu = scan.nextInt();
			System.out.println();
			
			switch(A_menu) {//��ȭ ���� ���α׷��� �޴�
			case 1:	//�α���
				System.out.println("*******�α���*******");
				System.out.print("ID : ");
				A_login_id = scan.next();
				System.out.print("Password : ");
				A_login_pw = scan.next();
				System.out.println();
				for(int i=1;i<=memberCount;i++) {	//��ü ������ Ȯ��
					if(A_login_id.equals(userList[i].getID())&&A_login_pw.equals(userList[i].getPW())) {
						while(true) {
							System.out.println("*******���� ���α׷�*******");
							System.out.println("1. ��ȭ ���\n2. ���� Ȯ��\n3. ����");
							System.out.print("�޴��� �������ּ��� : ");
							B_menu = scan.nextInt();
							if(B_menu == 1) {
									System.out.println();
									System.out.println("*******��ȭ ���*******");
									for(int j=1;j<=8;j++) {
										System.out.println(movieList[j].toString());	//��ȭ ��� ���
									}
									System.out.println("1. ����\n2. ����");
									System.out.print("�޴��� �������ּ��� : ");
									B_buyTicketMenu = scan.nextInt();	//Ƽ�ϱ��ſ���
									System.out.println();
									if(B_buyTicketMenu == 1) {
										
										System.out.println("*******��ȭ ���*******");
										for(int k=1;k<=8;k++) {
											System.out.println(movieList[k].toString());	//��ȭ ��� ���
										}
										System.out.println();
										System.out.print("������ ��ȭ�� �������ּ��� : ");
										B_chooseMovie = scan.nextInt();	//������ ��ȭ
										System.out.println(movieList[B_chooseMovie].toString());
										//�¼� ����
										movieList[B_chooseMovie].printSeat();
										System.out.print("�¼��� �������ּ���(ex A1): ");
										B_chooseSeat = scan.next();
										ticketNum++;
										userList[i].buyTicket(B_chooseSeat, ticketNum, movieList[B_chooseMovie]);
										movieList[B_chooseMovie].chooseSeat(B_chooseSeat);
										System.out.println();
									}
									else if(B_buyTicketMenu == 2) {
										System.out.println("���� ���α׷����� ���ư��ϴ�.\n");
									
									}
								
							}
							
							else if(B_menu == 2) {
								userList[i].showTicketList();
								System.out.println("\nPress enter to go back to User program");
								scan.nextLine();
								while(scan.nextLine().isEmpty()!=true);
								System.out.println();
								continue;	
							}
							
							else if(B_menu == 3) {
								System.out.println("��ȭ ���� ���α׷����� ���ư��ϴ�.");
								System.out.println();
								break;
							}	
						}
					}	
					
					correct = true;
				}
				if(correct != true) {

							System.out.println("�α��ο� �����ϼ̽��ϴ�.\n");
							continue;
				}
				break;
				
			case 2:	//ȸ������
				
				System.out.println("*******ȸ�� ����*******");
				System.out.print("ID : ");
				A_ID = scan.next();
				System.out.print("PW : ");
				A_PW = scan.next();
				if(memberCount>=1) {
					for(int i=1;i<=memberCount;i++) {
						if(A_ID == userList[i].getID()) {
							continue;
						}	
					}
				}
				memberCount++;
				userList[memberCount] = new User(A_ID, A_PW);
				System.out.println();
				break;
				
			case 3: //����
				System.out.println("��ȭ ���� ���α׷��� �����մϴ�.");
				return;
			
			default:
				break;
			}
		}
		//scan.close();
	}
}
