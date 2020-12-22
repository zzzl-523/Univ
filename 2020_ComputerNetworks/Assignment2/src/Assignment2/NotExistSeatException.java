package Assignment2;

public class NotExistSeatException extends Exception {
	public NotExistSeatException() {
		super("NotExistSeatException!");
	}
	public NotExistSeatException(String message) {
		super(message);
	}
}
