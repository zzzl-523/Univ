package Assignment2;

public class Movie {
	private String name;
	private int time_s;
	private int time_f;
	private String time;
	private char[][] seatList = new char[8][8];//new쓰기
	private int jumyu=0;
	private int movie_num;
	
	public Movie(String name, int time_s, int time_f, int movie_num){
		this.name = name;
		this.time_s = time_s;
		this.time_f = time_f;
		this.time = time_s + ":00 - " + time_f + ":00";
		this.movie_num = movie_num;
		movieSeat_ini();	//처음에 초기화
	}
	
	public String getName() {
		return this.name;
	}
	public int getJumyu() {
		return this.jumyu;
	}
	public char[][] getSeatList() {
		return seatList;
	}
	public String getTime() {
		return this.time;
	}
	public int getTime_s() {
		return this.time_s;
	}
	public int getTime_f() {
		return this.time_f;
	}
	public int getMovieNum() {
		return this.movie_num;
	}

	public String toString() {
		return "제목 : " + this.name + " / 상영 시간 : " + this.time;
	}
	
	public void movieSeat_ini() {
		for(int i=1;i<=6;i++) {
			this.seatList[i][0] = (char) (65-1 + i);
		}
		for(int i=1;i<=6;i++) {
			this.seatList[0][i] = (char) (48 + i); //0이48
		}
		for(int row=1;row<=6;row++) {
			for(int col=1;col<=6;col++) {
				this.seatList[row][col] = 'O';
			}
		}
	}
	public void chooseSeat(String B_chooseSeat) {
		int row = (int)(B_chooseSeat.charAt(0))-64;
		int col = (int)(B_chooseSeat.charAt(1))-48;		
		
		this.seatList[row][col] = 'X';	//예매된 좌석 X표시
		this.jumyu++;
	}
	
	public void printSeat() {
		System.out.println("******좌       석******");
		for(int row=0;row<=6;row++) {
			for(int col=0;col<=6;col++) {
				System.out.print(this.seatList[row][col]+" ");
			}
			System.out.println();
		}
		System.out.println("******************");
	}	
}
