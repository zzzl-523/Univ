package Assignment2;

import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.FileOutputStream;
import java.util.*;

public class Theater {
	
	public static void main(String[] args) {
		int A_menu;
		String A_login_id, A_login_pw;
		String A_ID, A_PW;
		int A_DEPT;
		boolean correct = false;
		Member[] userList = new Member[50];
		int memberCount = 0;
		int B_menu;
		int B_buyTicketMenu, B_chooseMovie;
		String B_chooseSeat;
		int B_manager_menu;
		int ticketNum = 0;
		
		Scanner fin_movieList = null;
		Scanner fin_userList = null;
		Scanner fin_ticket_info = null;
		PrintWriter fout_userList = null;
		PrintWriter fout_ticket_info = null;
		
		try {
			fin_movieList = new Scanner(new FileInputStream("MovieList.txt"));
			fin_userList = new Scanner(new FileInputStream("UserList.txt"));
			fin_ticket_info = new Scanner(new FileInputStream("TicketList.txt"));
			
		}
		catch(FileNotFoundException e) {
			System.out.println("Problem opening files.");
			System.exit(0);
		}

		//�� ��� �޾ƿ���
		if(fin_userList.hasNextLine()) {
			int already_memCount = 0;
			String user_info = null;
			already_memCount = fin_userList.nextInt();
			fin_userList.nextLine();
			for(int i=1;i<=already_memCount;i++) {
				user_info = fin_userList.nextLine();
				String[] user_array = user_info.split(" ");
				
				memberCount++;
				if(Integer.parseInt(user_array[0]) == 0) {
					userList[memberCount] = new User(user_array[1], user_array[2], Integer.parseInt(user_array[0]));
				}
				else {
					userList[memberCount] = new Manager(user_array[1], user_array[2], Integer.parseInt(user_array[0]));
				}
			}
	
		}
	
		
		//��ȭ ��� �޾ƿ���
		String movie_info = null;
		int movie_howmany = 0;
		movie_howmany = fin_movieList.nextInt();
		Movie[] movieList = new Movie[movie_howmany + 1];
		fin_movieList.nextLine();
		for(int i=1;i<=movie_howmany;i++) {
			movie_info = fin_movieList.nextLine();
			String[] array = movie_info.split("/");
			movieList[i] = new Movie(array[0], Integer.parseInt(array[1]), Integer.parseInt(array[2]), i); //��ȭ ��� �����
		}
		
		//Ƽ�� ���� �޾ƿ���
			while(fin_ticket_info.hasNextLine()) {
				String ticket_info = fin_ticket_info.nextLine();
				String[] ticket_array = ticket_info.split("/");
				for(int i=1;i<=memberCount;i++) {
					if(ticket_array[0].equals(userList[i].getID())) {
						ticketNum++;
						userList[i].buyTicket(ticket_array[4], ticketNum, movieList[Integer.parseInt(ticket_array[1])]);
						movieList[Integer.parseInt(ticket_array[1])].chooseSeat(ticket_array[4]);
					}	
				}
			}

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
				try {
					for(int i=1;i<=memberCount;i++) {	//��ü ������ Ȯ��
					
						if(A_login_id.equals(userList[i].getID())&&A_login_pw.equals(userList[i].getPW())) {
							
								while(true) {
									System.out.println("*******���� ���α׷�*******");
									System.out.println("1. ��ȭ ���\n2. ���� Ȯ��\n3. ��ȭ�� ����\n4. ����");
									System.out.print("�޴��� �������ּ��� : ");
									B_menu = scan.nextInt();
									try {
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
												System.out.print("������ ��ȭ�� �������ּ��� : ");
												B_chooseMovie = scan.nextInt();	//������ ��ȭ
												System.out.println();
												System.out.println(movieList[B_chooseMovie].toString());
												//�¼� ����
												try {
													if(userList[i].getDEPT() == 1) {
														System.out.println();
														System.out.printf("\"%s\" ��ȭ�� �¼� ���� ������: %.2f%n" , movieList[B_chooseMovie].getName(), (movieList[B_chooseMovie].getJumyu()/36.0) * 100.0 );
														System.out.printf("\"%s\" ��ȭ�� �� �����: %d%n" , movieList[B_chooseMovie].getName(), movieList[B_chooseMovie].getJumyu() * 10000 );
														System.out.println();
													}
												
													movieList[B_chooseMovie].printSeat();
													System.out.print("�¼��� �������ּ���(ex A1): ");
													B_chooseSeat = scan.next();
													
													int row = (int)(B_chooseSeat.charAt(0))-64;
													int col = (int)(B_chooseSeat.charAt(1))-48;
													
													if(row>6||col>6) {
														throw new NotExistSeatException(B_chooseSeat + " does not exist.");
													}
													if(movieList[B_chooseMovie].getSeatList()[row][col]=='X') {
														throw new DuplicatedReservationException(B_chooseSeat + " is already reserved.");
													}
													else {
														ticketNum++;
														userList[i].buyTicket(B_chooseSeat, ticketNum, movieList[B_chooseMovie]);
														movieList[B_chooseMovie].chooseSeat(B_chooseSeat);
														System.out.println();
													}
												}
												catch(DuplicatedReservationException e) {
													String message = e.getMessage();
													System.out.println(message);
												}
												catch(NotExistSeatException e) {
													String message = e.getMessage();
													System.out.println(message);
												}
											}
										
											else if(B_buyTicketMenu == 2) {
												System.out.println("���� ���α׷����� ���ư��ϴ�.\n");
											
											}
											else {
												throw new InvalidMenuException(B_buyTicketMenu + " is an invalid menu number");
											}
										}
										else if(B_menu == 2) {
											if(userList[i].getDEPT() == 0) {
												System.out.println("*******���� ���*******");	
												userList[i].showTicketList();
											}
											else {
												System.out.println("\n�����ڰ� ������ Ƽ�� ��: " + userList[i].getCount());
												System.out.println("�����: " + userList[i].getCount()*10000);
												System.out.println("-----------------------------------------------------------------------------");
												userList[i].showTicketList();
												System.out.println("-----------------------------------------------------------------------------");
											}
											
											System.out.println("\nPress enter to go back to User program");
											scan.nextLine();
											while(scan.nextLine().isEmpty()!=true);
											System.out.println();
											continue;	
										}
										else if(B_menu == 3) {
											if(userList[i].getDEPT() == 0) {
												throw new InvalidMenuException("Invalid Access.");	
											}
											else if(userList[i].getDEPT() == 1) {
												while(true) {
													try {
														System.out.println("\n*******��ȭ�� ����*******");
														System.out.println("1. ��ȭ�� ����\n2. ���� ����\n3. ����");
														System.out.print("�޴��� �������ּ��� : ");
														int B_control_menu = scan.nextInt();
														
														
														if(B_control_menu==1) {//��ȭ�� ����
															int sum=0, max=0, index=0;
															int count=0;
															
															Movie[] fakeMovieList = new Movie[movie_howmany+1];
															for(int k=1;k<=movie_howmany;k++) {
																fakeMovieList[k]= movieList[k];
																
															}
															for(int l=1;l<=movie_howmany;l++) {
																max=0;
															
																if(movieList[l].getJumyu()!=0) {
																	count++;
																}
	
																sum += movieList[l].getJumyu();
																
																for(int m=l;m<=movie_howmany;m++) {
																	if(max<fakeMovieList[m].getJumyu()) {
																		max = fakeMovieList[m].getJumyu();
																		index = m;
																	}
																
																}
																
																Movie temp;
																temp = fakeMovieList[l];
																fakeMovieList[l] = fakeMovieList[index];
																fakeMovieList[index] = temp;
																
															}
															
															
															System.out.println("\n������ ��ü �¼� ��: " + sum);
															System.out.printf("��ü �¼� ���� ������: %.2f%n" , sum/(36.0*movie_howmany) * 100);
															System.out.println("��ȭ�� �� �����: " + sum*10000);
															
															System.out.println("\n ������ ��Ȳ");
															System.out.println("----------------------------");
																
															for(int cnt=1;cnt<=count;cnt++) {
																System.out.println(cnt + "��: " + fakeMovieList[cnt].getName() + "(�¼���: " + fakeMovieList[cnt].getJumyu() + ")");
															}
															
															System.out.println("----------------------------");
															break;
														}
														else if(B_control_menu == 2) {
															System.out.print("\nã������ ID : ");
															String B_control_findID = scan.next();
							
															for(int f=1;f<=memberCount;f++) {
																if(B_control_findID.equals(userList[f].getID())) {
																	System.out.println();
																	System.out.println(B_control_findID + " ������ ������ Ƽ�� ��: " + userList[f].getCount());
																	
																	System.out.println("-----------------------------------------------------------------------------");
																	userList[f].showTicketList();
																	System.out.println("-----------------------------------------------------------------------------");
																	System.out.println();
																}
															}
															break;
														}
														else if(B_control_menu == 3) {
															break;
														}
														else {
															throw new InvalidMenuException(B_control_menu + " is an invalid menu number.");
														}
													}
													catch(InvalidMenuException e) {
														String message = e.getMessage();
														System.out.println(message);
													}	
												}
											}
										}	
										else if(B_menu == 4) {
											System.out.println("��ȭ ���� ���α׷����� ���ư��ϴ�.");										
											System.out.println();
											break;
										}	
										else {
											throw new InvalidMenuException(B_menu + " is an invalid menu number.");
										}
									}
									
									catch(InvalidMenuException e) {
										String message = e.getMessage();
										System.out.println(message);
									}	
								}
								correct = true;
						}			
					}
				
					if(correct != true) {
						throw new InvalidLoginException("Login failed.");
					}
				}
				catch(InvalidLoginException e) {
					String message = e.getMessage();
					System.out.println(message);
					continue;
				}
				break;
				
			case 2:	//ȸ������
				try {
					System.out.println("*******ȸ�� ����*******");
					System.out.print("ID : ");
					A_ID = scan.next();
					if(memberCount>=1) {
						for(int i=1;i<=memberCount;i++) {
							if(A_ID.equals(userList[i].getID())) {
								throw new DuplicatedIdException(A_ID + " already exists.");
							}	
						}
					}
					System.out.print("Password : ");
					A_PW = scan.next();
					System.out.print("Are you manager? : ");
					A_DEPT = scan.nextInt();
					
					memberCount++;
					if(A_DEPT == 0) {
						userList[memberCount] = new User(A_ID, A_PW, A_DEPT);	
					}
					else if(A_DEPT == 1) {
						userList[memberCount] = new Manager(A_ID, A_PW, A_DEPT);
					}
					System.out.println();
				}
				catch(DuplicatedIdException e){
					String message = e.getMessage();
					System.out.println(message);
				}
				break;
			case 3: //����
				try {
					fout_userList = new PrintWriter(new FileOutputStream("UserList.txt"));
					fout_ticket_info = new PrintWriter(new FileOutputStream("TicketList.txt"));
				}
				catch(FileNotFoundException e) {
					System.out.println("Problem opening files.");
					System.exit(0);
				}
				fout_userList.println(memberCount);
				for(int i=1;i<=memberCount;i++) {
					fout_userList.println(userList[i].getDEPT()+ " " + userList[i].getID() + " " + userList[i].getPW());
					for(int j=1;j<=userList[i].getCount();j++) {
						fout_ticket_info.println(userList[i].getID() + "/" + userList[i].getMyTicket(j));	
					}
				}
				
				System.out.println("��ȭ ���� ���α׷��� �����մϴ�.");
				
				fin_movieList.close();
				fin_userList.close();
				fout_userList.close();
				fout_ticket_info.close();
				return;
			
			default:
				break;
			}	
		}	
	}
}

