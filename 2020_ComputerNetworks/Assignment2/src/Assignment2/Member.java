package Assignment2;

public class Member {
	private String ID;
	private String PW;
	private int DEPT;
	private Ticket[] myTicket = new Ticket[50];
	private int count;
	
	Member(String ID, String PW, int DEPT){
		this.ID = ID;
		this.PW = PW;
		this.DEPT = DEPT;
	}
	
	public String getID() {
		return ID;
	}
	public String getPW() {
		return PW;
	}
	public int getDEPT() {
		return DEPT;
	}
	public int getCount() {
		return this.count;
	}
	public String getMyTicket(int a) {
		return myTicket[a].toString();
	}
	
	
	public void buyTicket(String B_chooseSeat, int ticketNum, Movie movie) {
		this.count++;
		myTicket[this.count] = new Ticket(B_chooseSeat, ticketNum, movie);
		
	}
	
	public void showTicketList() {
		
		for(int i=1;i<=count;i++) {
			myTicket[i].printTicket();
		}
	}
	

}
