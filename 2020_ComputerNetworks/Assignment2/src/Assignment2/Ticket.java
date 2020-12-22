package Assignment2;

public class Ticket {	//ÁÂ¼® ¼±ÅÃ
	
	private int ticketN;
	private Movie movie;
	private String seat;

	public Ticket(String B_chooseSeat, int ticketN, Movie movie){
		this.ticketN = ticketN;
		this.movie = movie;
		this.seat = B_chooseSeat;
	}
	public String toString() {
		return this.movie.getMovieNum() + "/" + this.movie.getTime_s() + "/" + this.movie.getTime_f() + "/" + this.seat;
	}
	public void printTicket() {
		System.out.println("Ticket number: " + this.ticketN + "/" + this.movie.toString() + "/" + "Seat: " + this.seat);
	}
}
