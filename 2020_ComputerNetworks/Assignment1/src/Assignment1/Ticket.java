package Assignment1;

public class Ticket {	//ÁÂ¼® ¼±ÅÃ
	
	int ticketN;
	Movie movie;
	String seat;

	Ticket(String B_chooseSeat, int ticketN, Movie movie){
		this.ticketN = ticketN;
		this.movie = movie;
		this.seat = B_chooseSeat;
	}
	public void printTicket() {
		System.out.println("Ticket number: " + this.ticketN + "/" + this.movie.toString() + "/" + "Seat: " + this.seat);
	}
}
