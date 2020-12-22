package Assignment2;

public class DuplicatedReservationException extends Exception {
	public DuplicatedReservationException() {
		super("DuplicatedReservationException!");
	}
	public DuplicatedReservationException(String message) {
		super(message);
	}
}
