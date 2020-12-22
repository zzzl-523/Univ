package Assignment2;

public class InvalidLoginException extends Exception {
	public InvalidLoginException() {
		super("InvalidLoginException!");
	}
	public InvalidLoginException(String message) {
		super(message);
	}
}
