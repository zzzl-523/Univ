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

		
		//영화 목록 만들기
		movieList[1] = new Movie("기생충", 0, 3);
		movieList[2] = new Movie("감기", 3, 6);
		movieList[3] = new Movie("해리포터", 6, 9);
		movieList[4] = new Movie("라라랜드", 9, 12);
		movieList[5] = new Movie("겨울왕국", 12, 15);
		movieList[6] = new Movie("명탐정 코난", 15, 18);
		movieList[7] = new Movie("어벤져스", 18, 21);
		movieList[8] = new Movie("국제시장", 21, 24);
		
		
		Scanner scan = new Scanner(System.in);
		while(true) {
			System.out.println("*******영화 예매 프로그램*******");
			System.out.println("1. 로그인\n2. 회원가입\n3. 종료");
			System.out.print("메뉴를 선택해주세요 : ");
			A_menu = scan.nextInt();
			System.out.println();
			
			switch(A_menu) {//영화 예매 프로그램의 메뉴
			case 1:	//로그인
				System.out.println("*******로그인*******");
				System.out.print("ID : ");
				A_login_id = scan.next();
				System.out.print("Password : ");
				A_login_pw = scan.next();
				System.out.println();
				for(int i=1;i<=memberCount;i++) {	//전체 돌리며 확인
					if(A_login_id.equals(userList[i].getID())&&A_login_pw.equals(userList[i].getPW())) {
						while(true) {
							System.out.println("*******유저 프로그램*******");
							System.out.println("1. 영화 목록\n2. 예매 확인\n3. 종료");
							System.out.print("메뉴를 선택해주세요 : ");
							B_menu = scan.nextInt();
							if(B_menu == 1) {
									System.out.println();
									System.out.println("*******영화 목록*******");
									for(int j=1;j<=8;j++) {
										System.out.println(movieList[j].toString());	//영화 목록 출력
									}
									System.out.println("1. 예매\n2. 종료");
									System.out.print("메뉴를 선택해주세요 : ");
									B_buyTicketMenu = scan.nextInt();	//티켓구매여부
									System.out.println();
									if(B_buyTicketMenu == 1) {
										
										System.out.println("*******영화 목록*******");
										for(int k=1;k<=8;k++) {
											System.out.println(movieList[k].toString());	//영화 목록 출력
										}
										System.out.println();
										System.out.print("예매할 영화를 선택해주세요 : ");
										B_chooseMovie = scan.nextInt();	//선택한 영화
										System.out.println(movieList[B_chooseMovie].toString());
										//좌석 선택
										movieList[B_chooseMovie].printSeat();
										System.out.print("좌석을 선택해주세요(ex A1): ");
										B_chooseSeat = scan.next();
										ticketNum++;
										userList[i].buyTicket(B_chooseSeat, ticketNum, movieList[B_chooseMovie]);
										movieList[B_chooseMovie].chooseSeat(B_chooseSeat);
										System.out.println();
									}
									else if(B_buyTicketMenu == 2) {
										System.out.println("유저 프로그램으로 돌아갑니다.\n");
									
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
								System.out.println("영화 예매 프로그램으로 돌아갑니다.");
								System.out.println();
								break;
							}	
						}
					}	
					
					correct = true;
				}
				if(correct != true) {

							System.out.println("로그인에 실패하셨습니다.\n");
							continue;
				}
				break;
				
			case 2:	//회원가입
				
				System.out.println("*******회원 가입*******");
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
				
			case 3: //종료
				System.out.println("영화 예매 프로그램을 종료합니다.");
				return;
			
			default:
				break;
			}
		}
		//scan.close();
	}
}
