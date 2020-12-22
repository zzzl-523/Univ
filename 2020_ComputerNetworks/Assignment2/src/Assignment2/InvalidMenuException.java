package Assignment2;

public class InvalidMenuException extends Exception {
	public InvalidMenuException() {
		super("InvalidMenuException!");
	}
	public InvalidMenuException(String message) {
		super(message);
	}
}
