package Assignment2;

public class DuplicatedIdException extends Exception {
	public DuplicatedIdException() {
		super("DuplicatedIdException!");
	}
	public DuplicatedIdException(String message) {
		super(message);
	}
}
