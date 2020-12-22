package Assignment1;

public class User {
	private String ID;
	private String PW;
	private Ticket[] myTicket = new Ticket[50];
	int count;
	
	User(String ID, String PW){
		this.ID = ID;
		this.PW = PW;
	}
	
	public String getID() {
		return ID;
	}
	public String getPW() {
		return PW;
	}

	public void buyTicket(String B_chooseSeat, int ticketNum, Movie movie) {
		this.count++;
		myTicket[this.count] = new Ticket(B_chooseSeat, ticketNum, movie);
		//this.ticketNum = ticketNum;
	}
	
	public void showTicketList() {
		System.out.println("*******예매 목록*******");
		for(int i=1;i<=count;i++) {
			myTicket[i].printTicket();
		}
	}
	
	
}
